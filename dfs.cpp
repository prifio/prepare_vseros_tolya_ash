#include <bits/stdc++.h>

#define mp make_pair

using namespace std;
typedef pair<int, int> pii;

const int N = 100000;

vector<int> g[N];
int us[N];

void dfs(int v)
{
    us[v] = 1;
    for (int i : g[v])
        if (!us[i])
            dfs(i);
}

void get_ans(int n)
{
    for (int i = 0; i < n; ++i)
        g[i].resize(0);
    for(int i = 0; i < n; ++i)
        us[i] = 0;
    int m;
    scanf("%d", &m):
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
        if (!us[i])
        {
            dfs(i);
            ++k;
        }
    if (k == 1)
        printf("YES\n\n");
    else
        printf("NO\n\n");    
}

int main()
{
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    int n;
    while (scanf("%d", &n) == 1)
        get_ans(n);
    return 0;
}