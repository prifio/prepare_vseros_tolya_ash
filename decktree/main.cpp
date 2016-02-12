#include <bits/stdc++.h>

using namespace std;

struct note
{
    note *le, *r;
    int y, sz;
    int data;
    int sum = 0;
    void recalc()
    {
        sz = 1 + ((le == NULL) ? 0 : le -> sz) + ((r == NULL) ? 0 : r -> sz);
        sum = data + ((le == NULL) ? 0 : le -> sum) + ((r == NULL) ? 0 : r -> sum);
    }
};

note get_note(int a)
{
    note ans;
    ans.y = rand();
    ans.sz = 1;
    ans.le = ans.r = NULL;
    ans.data = ans.sum = a;
    return ans;
}

note* merge_note(note* a, note* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a -> y > b -> y)
    {
        note* ans = a;
        ans -> r = merge_note(a -> r, b);
        ans -> recalc();
        return ans;
    }
    note* ans = b;
    ans -> le = merge_note(a, b -> le);
    ans -> recalc();
    return ans;
}

pair<note*, note*> splite(note* a, int k)
{
    if (a == NULL)
        return make_pair((note*)NULL, (note*)NULL);
    if ((k == 0) || (a -> le != NULL && a -> le -> sz >= k))
    {
        auto hlp = splite(a -> le, k);
        note* right = a;
        right -> le = hlp.second;
        right -> recalc();
        return make_pair(hlp.first, right);
    }
    auto hlp = splite(a -> r, k - 1 - ((a -> le == NULL) ? 0 : a -> le -> sz));
    note* left = a;
    left -> r = hlp.first;
    left -> recalc();
    return make_pair(left, hlp.second);
}

note* get_key(note* a, int ind)
{
    int szleft = (a -> le == NULL) ? 0 : a -> le -> sz;
    if (szleft == ind)
        return a;
    if (szleft >= ind)
        return get_key(a -> le, ind);
    return get_key(a -> r, ind - szleft - 1);
}

void up_key(note* a, int ind, int up)
{
    int szleft = (a -> le == NULL) ? 0 : a -> le -> sz;
    if (szleft == ind)
        a -> data += up;
    if (szleft > ind)
        up_key(a -> le, ind, up);
    else if (szleft < ind)
        up_key(a -> r, ind - szleft - 1, up);
    a -> recalc();
}

void change_key(note* a, int ind, int dat)
{
    up_key(a, ind, -get_key(a, ind) -> data + dat);
}



int main()
{
    note* mass = NULL;
    int n;
    scanf("%d", &n);
    note vrtx[n];
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        vrtx[i] = get_note(a);
        mass = merge_note(mass, &vrtx[i]);
    }
    change_key(mass, 2, 10);
    cout << splite(mass, 3).first -> sum << " " << get_key(mass, 2) -> data;
    return 0;
}
