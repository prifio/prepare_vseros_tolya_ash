#include <bits/stdc++.h>

using namespace std;

struct note
{
    note *le, *r;
    int y, sz;
    int data, ind;
    int sum = 0;
    void recalc()
    {
        sz = 1 + ((le == NULL) ? 0 : le -> sz) + ((r == NULL) ? 0 : r -> sz);
        sum = data + ((le == NULL) ? 0 : le -> sum) + ((r == NULL) ? 0 : r -> sum);
    }
};

note get_note(int a, int i)
{
    note ans;
    ans.y = rand();
    ans.sz = 1;
    ans.le = ans.r = NULL;
    ans.data = ans.sum = a;
    ans.ind = i;
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
        a -> r = merge_note(a -> r, b);
        a -> recalc();
        return a;
    }
    b -> le = merge_note(a, b -> le);
    b -> recalc();
    return b;
}

pair<note*, note*> splite(note* a, int k)
{
    if (a == NULL)
        return make_pair((note*)NULL, (note*)NULL);
    if (k == 0)
        return make_pair((note*)NULL, a);
    if (a -> le != NULL && a -> le -> sz >= k)
    {
        auto hlp = splite(a -> le, k);
        a -> le = hlp.second;
        a -> recalc();
        return make_pair(hlp.first, a);
    }
    auto hlp = splite(a -> r, k - 1 - ((a -> le == NULL) ? 0 : a -> le -> sz));
    a -> r = hlp.first;
    a -> recalc();
    return make_pair(a, hlp.second);
}

void printn(note* a)
{
    if (a == NULL)
        return;
    printn(a -> le);
    printf("%d ", a -> data);
    printn(a -> r);
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

note* lower(note* a, int ind)
{
    if (a == NULL)
        return a;
    note* mi;
    if (a -> ind >= ind)
    {
        mi = lower(a -> le);
        if (mi == NULL)
            return a;
        return mi;
    }
    mi = lower(a -> r);
    return mi;
}

int main()
{
    freopen("movetofront.in", "r", stdin);
    freopen("movetofront.out", "w", stdout);
    note* mass = NULL;
    int n, m;
    scanf("%d%d", &n, &m);
    note vrtx[n];
    for (int i = 0; i < n; ++i)
    {
        vrtx[i] = get_note(i + 1);
        mass = merge_note(mass, &vrtx[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int le, r;
        scanf("%d%d", &le, &r);
        auto spl1 = splite(mass, le - 1);
        auto spl2 = splite(spl1.second, r - le + 1);
        mass = merge_note(spl2.first, merge_note(spl1.first, spl2.second));
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", get_key(mass, i) -> data);
    return 0;
}
