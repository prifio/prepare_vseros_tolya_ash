#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int m = a + b + c;
    vector<int> v[3];
    for (int i = 0; i < n; ++i)
    {
        int ye, lvl;
        scanf("%d%d", &ye, &lvl);
        v[ye].push_back(lvl);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    int le0 = v[0].size(), le1 = v[1].size(), le2 = v[2].size();
    int yk1 = 0, yk2 = 0;
    int minans = 1e9;
    int a1, b1, c1;
    for (int i = 0; i < le0; ++i)
    {
        while (yk1 < le1 && v[1][yk1] < v[0][i])
            ++yk1;
        while (yk2 < le2 && v[2][yk2] < v[0][i])
            ++yk2;
        if (m - n + i + yk1 + yk2 >= 0)
        {
            int le = -1, r = yk1;
            while (r - le > 1)
            {
                int mid = (r + le) / 2;
                //m = n - i - mid - yk2'
                if (-m + n - i - mid >= 0 && v[1][mid] > v[2][n - i - mid - m])
                    r = mid;
                else
                    le = mid;
            }
            le = r;
            r = yk1 - 1;
            while (r - le > 2)
            {
                int mid1 = (2 * le + r) / 3;
                int mid2 = (le + 2 * r) / 3;
                if (abs(le1 - mid1 - b) + abs(le2 + m - n + i + mid1 - c) <
                    abs(le1 - mid2 - b) + abs(v[2].size() + m - n + i + mid2 - c)
                    )
                    r = mid2;
                else
                    le = mid1;
            }
            if (le < le1 && -m + n - i - le < le2)
            {
                int hlp = minans;
                minans = min(minans, abs(le1 - le - b) + abs(le2 + m - n + i + le - c) + abs(le0 - i - a));
                if (hlp != minans)
                {
                    a1 = le0 - i;
                    b1 = le1 - le;
                    c1 = le2 + m - n + i + le;
                }
            }
            if (le + 1 < yk1 && -m + n - i - le - 1 < le2)
            {
                int hlp = minans;
                minans = min(minans, abs(le1 - le - 1 - b) + abs(le2 + m - n + i + le + 1 - c) + abs(le0 - i - a));
                if (hlp != minans)
                {
                    a1 = le0 - i;
                    b1 = le1 - le - 1;
                    c1 = le2 + m - n + i + le + 1;
                }
            }
            if (le + 2 < yk1 && -m + n - i - le - 2 < le2)
            {
                int hlp = minans;
                minans = min(minans, abs(le1 - le - 2 - b) + abs(le2 + m - n + i + le + 2 - c) + abs(le0 - i - a));
                if (hlp != minans)
                {
                    a1 = le0 - i;
                    b1 = le1 - le - 2;
                    c1 = le2 + m - n + i + le + 2;
                }
            }
        }
    }
    cout << minans << a1 << b1 << c1;
    return 0;
}
