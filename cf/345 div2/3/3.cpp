#include <bits/stdc++.h>

using namespace std;

bool cmp(int a1, int a2)
{
    return -a1 < -a2;
}

void sol(int n)
{
    long long good = 0;
    map<int, int> mpx, mpy;
    map<pair<int, int>, int> mpxy;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        mpx[a] = mpx[a] + 1;
        mpy[b] = mpy[b] + 1;
        mpxy[make_pair(a, b)] = mpxy[make_pair(a, b)]  + 1;
    }
    long long ans = 0;
    for (auto i : mpx)
        ans += (long long)i.second * (i.second - 1) / 2;
    for (auto i : mpy)
        ans += (long long)i.second * (i.second - 1) / 2;
    for (auto i : mpxy)
        ans -= (long long)i.second * (i.second - 1) / 2;
    cout << ans << "\n";
}


int main()
{
    //freopen("test.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
        sol(n);
    return 0;
}
