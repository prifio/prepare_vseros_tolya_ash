#include <bits/stdc++.h>

using namespace std;


bool cmp(int a1, int a2)
{
    return -a1 < -a2;
}

void sol(int n)
{
    int a[n];
    for (int &i : a)
        scanf("%d", &i);
    sort(a, a + n);
    vector<int> b;
    int ch = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1])
            ++ch;
        else
        {
            b.push_back(ch);
            ch = 1;
        }
    b.push_back(ch);
    sort(b.begin(), b.end(), cmp);
    int ans = 0;
    ch = 0;
    while (b.size() > 0)
    {
        int hlp = b.back();
        ans += (b.size() - 1) * (hlp - ch);
        ch = hlp;
        while (b.size() > 0 && b.back() == hlp)
            b.pop_back();
    }
    printf("%d\n", ans);
}


int main()
{
    //freopen("test.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
        sol(n);
    return 0;
}
