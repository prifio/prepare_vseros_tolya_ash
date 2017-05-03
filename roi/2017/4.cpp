#include <bits/stdc++.h>

#define mp make_pair

typedef std::pair<int, int> pii;

struct CHT
{
    std::vector<std::pair<long long int, long long int> > lines;
    std::vector<long double> cross;
    long double cross_x(long long int a1, long long int b1, long long int a2, long long int b2)
    {
        return (b2 - b1) / (long double)(a1 - a2);    
    }
    void clean()
    {
        while (lines.size() > 0)
            lines.pop_back();
        while (cross.size() > 0)
            cross.pop_back();
    }    
    void add_line(long long int a, long long int b)
    {
        int do_it = 1;
        while (lines.size() >= 2 && do_it)
        {
            std::pair<long long int, long long int> li = lines.back();
            do_it = cross.back() >= cross_x(li.first, li.second, a, b);
            if (do_it)
            {
                lines.pop_back();    
                cross.pop_back();
            }
        }
        if (lines.size() >= 1)
            cross.push_back(cross_x(lines.back().first, lines.back().second, a, b));    
        lines.push_back(std::mp(a, b));
    }
    long long int get(long long int x)
    {
        int le = -1, r = lines.size() - 1;
        while (r - le > 1)
        {
            int mid = (r + le) / 2;
            if (cross[mid] > x)
                r = mid;
            else
                le = mid;
        }
        return lines[le + 1].first * x + lines[le + 1].second;
    }
    int size()
    {
        return lines.size();
    }
};

void get_ans(int n, int m)
{
    std::vector<int> t[m], v[m];
    for (int i = 0; i < m; ++i)
    {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            --a;
            t[i].push_back(b);
            v[i].push_back(a);
        }
        scanf("%d", &cnt);
        --cnt;
        v[i].push_back(cnt);
    }
    std::vector<pii> g[n];
    int finish = n - 1, start = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < t[i].size(); ++j)
        {
            g[v[i][j]].push_back(std::mp(t[i][j], v[i][j + 1]));     
        }
    std::set<std::pair<long long int, int> > st;
    long long int dist[n];
    for (int i = 0; i < n; ++i)
    {    
        if (i == start)
            dist[i] = 0;
        else
            dist[i] = 1000000000000000000;
        st.insert(std::mp(dist[i], i));
    }
    std::vector<int> perm;
    for (int i = 0; i < n; ++i)
    {
        auto mi = *st.begin();
        st.erase(mi);
        int curv = mi.second;
        perm.push_back(curv);
        //std::cout << g[curv].size() << " " << curv << "\n";       
        for (auto j : g[curv])
            if (dist[j.second] > dist[curv] + j.first)
            {
                st.erase(std::mp(dist[j.second], j.second));
                dist[j.second] = dist[curv] + j.first;
                st.insert(std::mp(dist[j.second], j.second));
            }
    }    
    long long int ans[n];
    for (int i = 0; i < n; ++i)
        ans[i] = 0;
    int cnt_color = -1;
    std::vector<std::pair<int, pii> > colors[n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (j == 0 || dist[v[i][j]] - dist[v[i][j - 1]] < t[i][j - 1])
                ++cnt_color;
            colors[v[i][j]].push_back(std::mp(cnt_color, std::mp(i, j)));
        }
    ++cnt_color;
    CHT cht[cnt_color];
    for (int i = 0; i < n; ++i)
    {
        int cur_v = perm[i];
        for (auto j : colors[cur_v])
        {
            int color = j.first, way = j.second.first, num = j.second.second;
            if (num != 0 && dist[cur_v] - dist[v[way][num - 1]] == t[way][num - 1])
                ans[cur_v] = std::max(ans[cur_v], dist[cur_v] * dist[cur_v] - cht[color].get(-dist[cur_v]));
        }
        for (auto j : colors[cur_v])
        {
            int way = j.second.first, color = j.first;
            cht[color].add_line(-2 * dist[cur_v], -ans[cur_v] - dist[cur_v] * dist[cur_v]);                        
        }
    }
//    for (int i = 0; i < n; ++i)
//        std::cout << ans[i] << "\n";
    std::cout << dist[finish] << " " << ans[finish] << "\n";
}

int main()
{
    freopen("trains.in", "r", stdin);
    freopen("trains.out", "w", stdout);
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        get_ans(n, m);
    }
    return 0;
}