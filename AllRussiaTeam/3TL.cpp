#include <bits/stdc++.h>

#define make_pair mp

using namespace std;

int sig(int a)
{
    if (a > 0)
        return 1;
    if (a == 0)
        return 0;
    return -1;
}

void get_ans(int n, int le, int r)
{
    int b[n], g[n];
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &b[i], &g[i]);
    int ans[n + 1];
    ans[0] = 0;
    int del[n];
    for (int i = 0; i < n; ++i)
        del[i] = 0;
    int back[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = -1e9;
        for (int j = 0; j < i; ++j)
            del[j] += b[i - 1] - g[i - 1];
        for (int j = i - le; j >= 0 && j >= i - r; --j)
            if (ans[i] < ans[j] + sig(del[j]))
            {
                ans[i] = ans[j] + sig(del[j]);
                back[i] = j;
            }
    }
    vector<int> vans;
    int now = n;
    while (now > 0)
    {
        vans.push_back(now);
        now = back[now];
//        cout << now;    
    }
    printf("%d\n", vans.size());
    vans.push_back(0);
    for (int i = 0; i < vans.size() - 1; ++i)
    {
        printf("%d %d\n", vans[i + 1] + 1, vans[i]);
    }
}

int main()
{
    freopen("demo.in", "r", stdin);
//    freopen("w", "demo.out", stdout);
    int n, le, r;
    while (scanf("%d%d%d", &n, &le, &r) == 3)
        get_ans(n, le, r);       
    return 0;
}