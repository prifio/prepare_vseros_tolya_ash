#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> p1, pair<int, int> p2)
{
    return p1 > p2;
}

void sol(int n)
{
    pair<int, int> a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n, cmp);
    int ans = 1;
    int masans[n];
    masans[a[0].second] = ans;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].first != a[i - 1].first)
            ans = i + 1;
        masans[a[i].second] = ans;
    }
    for (int i : masans)
        printf("%d ", i);
    printf("\n");
}


int main()
{
    freopen("test.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
        sol(n);
    return 0;
}
