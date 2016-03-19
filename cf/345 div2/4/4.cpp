#include <bits/stdc++.h>

using namespace std;

bool cmp(int a1, int a2)
{
    return -a1 < -a2;
}

void sol(int n)
{
    int a, b, t;
    scanf("%d%d%d", &a, &b, &t);
    int reading[n];
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'h')
            reading[i] = 1;
        else
            reading[i] = 1 + b;
    if (t < reading[0])
    {
        printf("0\n");
        return;
    }
    t -= reading[0];
    int le[n], r[n];
    le[0] = r[0] = 0;
    for (int i = 1; i < n; ++i)
        le[i] = le[i - 1] + a + reading[i];
    for (int i = n - 1; i > 0; --i)
        r[i] = r[(i + 1) % n] + a + reading[i];
    if (le[n - 1] <= t)
    {
        printf("%d\n", n);
        return;
    }
    int yk = 1;
    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        int locans = le[i] + r[yk] + a * min(i, n - yk);
        while (yk < n && locans > t)
        {
            ++yk;
            locans = le[i] + r[yk] + a * min(i, n - yk);
        }
        if (locans <= t)
            ans = max(ans, i + 1 + n - yk);
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
