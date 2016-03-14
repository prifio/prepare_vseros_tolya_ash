#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int t[m];
    for (int &i : t)
        scanf("%d", &i);
    int ma = t[0];
    for (int i : t)
        ma = max(ma, i);
    printf("%d\n\n", ma * n);
    vector<pair<int, int>> v[n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            v[(n + j - i) % n].push_back(make_pair(j * ma, i));

    for (int i = 0; i < n; ++i)
    {
        sort(v[i].begin(), v[i].end());
        for(auto j : v[i])
            printf("%d %d\n", j.second + 1, j.first);
        printf("\n");
    }
    return 0;
}
