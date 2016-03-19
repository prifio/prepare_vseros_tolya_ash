#include <bits/stdc++.h>

using namespace std;

int ans[300][300];

int rabb(int a, int b)
{
    if (b == 0 || a == 0)
        return 0;
    if (a == 1 && b == 1)
        return 0;
    if (ans[a][b] != -1)
        return ans[a][b];
    int ma = 0;
    if (b > 1)
        ma = max(ma, rabb(a + 1, b - 2) + 1);
    if (a > 1)
        ma = max(ma, rabb(a - 2, b + 1) + 1);
    ans[a][b] = ma;
    return ma;
}

void sol(int n)
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 300; ++j)
            ans[i][j] = -1;
    printf("%d\n", rabb(n, m));
}


int main()
{
    //freopen("test.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1)
        sol(n);
    return 0;
}
