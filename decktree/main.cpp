#include <bits/stdc++.h>

using namespace std;

struct note
{
    note* le, r;
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
        sz = 1 + (le == NULL : 0 ? le -> sz) + (le == NULL : 0 ? r -> sz);
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



int main()
{

    return 0;
}
