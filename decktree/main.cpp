#include <bits/stdc++.h>

using namespace std;

struct note
{
    note *le, *r;
    int y, sz;
    int data;
    note(int a)
    {
        y = rand();
        sz = 1;
        le = r = NULL;
        data = a;
    }

    void recalc()
    {
        sz = 1 + ((le == NULL) ? 0 : le -> sz) + ((le == NULL) ? 0 : r -> sz);
    }
};

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
    if (note* a == NULL)
        return make_pair(NULL, NULL);
    if (a -> le != NULL && a -> le -> sz >= k)
    {
        auto hlp = splite(a -> le, k);
        note* right = a;
        right -> le = hlp.second;
        right -> recalc();
        return make_pair(hlp.first, right);
    }
    auto hlp = splite(a -> r, k - 1 - a -> le -> sz);
    note* right = a;
    right -> le = hlp.second;
    return make_pair(hlp.first, right);
}



int main()
{

    return 0;
}
