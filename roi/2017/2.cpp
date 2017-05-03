#include <bits/stdc++.h>

#define mp make_pair

typedef std::pair<int, int> pii;

int log2(int a)
{
    int ans = 0;
    while (a > 0)
    {
        a >>= 1;
        ++ans;
    }
    return ans - 1;
}

int get_num(int* lvl0, int* lvl1)
{
    int ans = 0;
    int is_bad = 0;
    for (int i = 0; i < 31; ++i)
    {
        is_bad = is_bad || (lvl0[i] > 0 && lvl1[i] > 0);
        if (lvl1[i] > 0)
            ans += (1 << i);
    }    
    if (is_bad)
        return -1;
    return ans;
}

void get_ans(int n)
{
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    int lvl0[31], lvl1[31];
    for (int i = 0; i < 31; ++i)
        lvl0[i] = lvl1[i] = 0;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] != a[i + 1])
        {
            int lg = log2(a[i] ^ a[i + 1]);
            if (a[i] < a[i + 1])
                ++lvl0[lg];
            else
                ++lvl1[lg];
        }
    printf("%d\n", get_num(lvl0, lvl1));
    for (int i = 0; i < q; ++i)
    {
        int ind, num;
        scanf("%d %d", &ind, &num);
        --ind;
        if (ind > 0 && a[ind] != a[ind - 1])
        {
            int lg = log2(a[ind] ^ a[ind - 1]);
            if (a[ind - 1] < a[ind])
                --lvl0[lg];
            else
                --lvl1[lg];
        }
        if (ind + 1 < n && a[ind] != a[ind + 1])
        {
            int lg = log2(a[ind] ^ a[ind + 1]);
            if (a[ind] < a[ind + 1])
                --lvl0[lg];
            else
                --lvl1[lg];
        }
        a[ind] = num;
        if (ind > 0 && a[ind] != a[ind - 1])
        {
            int lg = log2(a[ind] ^ a[ind - 1]);
            if (a[ind - 1] < a[ind])
                ++lvl0[lg];
            else
                ++lvl1[lg];
        }
        if (ind + 1 < n && a[ind] != a[ind + 1])
        {
            int lg = log2(a[ind] ^ a[ind + 1]);
            if (a[ind] < a[ind + 1])
                ++lvl0[lg];
            else
                ++lvl1[lg];
        }
        printf("%d\n", get_num(lvl0, lvl1));
    }
}

int main()
{
    freopen("order.in", "r", stdin);
    freopen("order.out", "w", stdout);
    int n;
    while (scanf("%d", &n) == 1)
        get_ans(n);
    return 0;
}