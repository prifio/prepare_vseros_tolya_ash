#include <bits/stdc++.h>

#define mp make_pair

typedef std::pair<int, int> pii;

long long int max(long long int a, long long int b)
{
    if (a > b)
        return a;
    return b;
}

long long int min(long long int a, long long int b)
{
    if (a < b)
        return a;
    return b;
}        

struct window
{
    int len;
    long long int *forw, *bac, *real_forw;
    int yk1, yk2, yk3;
    void add(long long int i)
    {
        forw[++yk1] = min(i, forw[yk1 - 1]);
        real_forw[++yk3] = i;
        if (yk1 == len)
            while (yk1 > 0)
            {
                bac[++yk2] = min(bac[yk2 - 1], real_forw[yk3--]);
                --yk1;
            }
    }
    void del()
    {
        --yk2;
    }
    long long int get_min()
    {
        return min(forw[yk1], bac[yk2]);   
    }
    void init(int lenG, long long int* a1, long long int* a2, long long int* a3)
    {
        len = lenG;
        forw = a1;
        bac = a2;
        real_forw = a3;
        yk1 = yk2 = 0;
        yk3 = -1;
        forw[yk1] = 1000000000000000000;
        bac[yk2] = 1000000000000000000;
    }
};  

long long int get_min(long long int* forw, long long int* back, int le, int r)
{
    if (r == le)
        return 1000000000000000000;
    return std::min(forw[r - 1], back[le]);            
}
    
void get_ans(int n)
{
    int a, le[n], r[n], c[n];
    scanf("%d", &a);
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &le[i], &r[i], &c[i]);
    long long int ans[a + 1];
    ans[0] = 0;
    int mir = 0;
    for (int i = 0; i < n; ++i)
        if (r[i] < r[mir])
            mir = i;
    for (int i = 0; i <= a; ++i)
        ans[i] = (long long int)i * -1000000000;
    pii sr[n];
    for (int i = 0; i < n; ++i)
        sr[i] = std::mp(r[i] - le[i] + 1, i);
    long long int memor[6100000];
    int yk = 0;
    std::sort(sr, sr + n);
    window windows[n];
    windows[0].init(sr[0].first, memor, memor + sr[0].first + 1, memor + 2 * sr[0].first + 2);
    yk = 3 * sr[0].first + 2;
    for (int i = 0; i < n - 1; ++i)
        if (sr[i + 1].first > sr[i].first)
        {    
            int cur_len = sr[i + 1].first - sr[i].first;
            windows[i + 1].init(cur_len, memor + yk, memor + cur_len + yk + 1, memor + 2 * cur_len + 2 + yk);
            yk += 3 * cur_len + 2;
        }
    for (int i = 0; i < a; ++i)
    {
        //i r[j] - le[j] + i          r[j] - le[j] + 1  x - r[j] = i
        long long int mi = 1000000000000000000;
        if (i > sr[0].first)
            windows[0].del();
        windows[0].add(ans[i]);
        for (int j = 1; j < n; ++j)
        {
            if (sr[j].first - sr[j - 1].first > 0)
            {
                if (i - sr[j].first >= 0)
                    windows[j].del();
                if (i - sr[j - 1].first >= 0)
                    windows[j].add(ans[i - sr[j - 1].first]);
            }
        }    
        for (int j = 0; j < n && sr[j].first <= i + 1; ++j)
        {
            int k = sr[j].second;
            if (sr[j].first - sr[j - 1].first > 0 || j == 0)
                mi = min(mi, windows[j].get_min());
            if (i + le[k] <= a)
                ans[i + le[k]] = max(ans[i + le[k]], mi - c[k]);
        }
    }
    std::cout << ans[a] + (long long int)a * 1000000000 << "\n";
}

int main()
{
    freopen("anti.in", "r", stdin);
    freopen("anti.out", "w", stdout);
    int n;
    while (scanf("%d", &n) == 1)
        get_ans(n);
    return 0;
}