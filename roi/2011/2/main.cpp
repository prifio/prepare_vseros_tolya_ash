#include <bits/stdc++.h>

using namespace std;

bool cmp (int a, int b)
{
    return a > b;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; ++tt)https://github.com/prifio/Coins_Hockey
    {
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int m = a + b + c;
    vector<int> v[3];
    for (int i = 0; i < n; ++i)
    {
        int ye, lvl;
        scanf("%d%d", &ye, &lvl);
        v[ye - 1994].push_back(lvl);
    }
    sort(v[0].begin(), v[0].end(), cmp);
    sort(v[1].begin(), v[1].end(), cmp);
    sort(v[2].begin(), v[2].end(), cmp);

    int le0 = v[0].size(), le1 = v[1].size(), le2 = v[2].size();
    int yk0 = 0, yk2 = 0;
    int minans = 1e9;
    int a1, b1, c1;
    for (int j = 0; j < le1; ++j)
    {
        while (yk0 < le0 && v[0][yk0] > v[1][j])
            ++yk0;
        while (yk2 < le2 && v[2][yk2] > v[1][j])
            ++yk2;

        //i >= 0
        //i <= yk0 - 1
        //n - j - i - 3 = k
        //n - j - 1 - i - 1  - 1 >= yk2   i <= n - j - 3 - yk2
        //n - j - 1 - i - 1  - 1 <= le2 - 1  i >= n - j - 2 - le2
        int le = max(0, m - j - 2 - le2);
        int r = min(yk0 - 1, m - j - 3 - yk2);
        if (r >= le)
        {
            int f3 = abs(b - j - 1) + abs(a - r - 1) + abs(c - m + j + r + 2);
            int f0 = abs(b - j - 1) + abs(a - le - 1) + abs(c - m + j + le + 2);
            int f1 = 1e9;
            if (a - 1 >= le && r >= a - 1)
                f1 = abs(b - j - 1) + abs(c - m + j + a + 1);
            int f2 = 1e9;
            if (m - j - 2 - c >= le && r >= m - j - 2 - c)
                f2 = abs(b - j - 1) + abs(a - m + j + 1 + c);
            if (f0 < minans)
            {
                minans = f0;
                a1 = le + 1;
                b1 = j + 1;
                c1 = m - le - 2 - j;
            }
            if (f3 < minans)
            {
                minans = f3;
                a1 = r + 1;
                b1 = j + 1;
                c1 = m - r - 2 - j;
            }
            if (f1 < minans)
            {
                minans = f1;
                a1 = a;
                b1 = j + 1;
                c1 = m - a - 1 - j;
            }
            if (f2 < minans)
            {
                minans = f2;
                a1 = m - c - j - 1;
                b1 = j + 1;
                c1 = c;
            }
        }
    }
    if (minans == 1e9)
        printf("-1\n");
    else
        cout << minans << " " <<  a1 << " " << b1 << " " << c1 << "\n";
    }
    return 0;
}
