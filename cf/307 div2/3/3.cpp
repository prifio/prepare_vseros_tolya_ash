#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> p1, pair<int, int> p2)
{
    return p1 > p2;
}

void sol(int n, int m)
{
    if (n == -1)
        exit(0);
    int a[n];
    for (int &i : a)
        scanf("%d", &i);
    long long le = n - 2, r = 1e15 + 1;
    while (r - le > 1)
    {
        long long mid = (le + r) / 2;
        int cnt = 0;
        long long left = mid;
        for (int i = 0; i < n && cnt < m; ++i)
        {
            int now = a[i];
            while (left <= now && cnt < m)
            {
                ++cnt;
                now -= left;
                left = mid - i;
            }
            left -= now + 1;
        }
        if (cnt < m || (cnt == m && left == mid - n))
            r = mid;
        else
            le = mid;
    }
    cout << (r + 1) << "\n";
}


int main()
{
    //freopen("test.in", "r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        sol(n, m);
    }
    return 0;
}
