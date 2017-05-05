#include <bits/stdc++.h>

#define mp make_pair

typedef std::pair<int, int> pii;

int x0, y0;

bool cmp(pii p1, pii p2)
{
    long long int x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
    if (x1 == x0 && y1 == y0)
        return true;
    if (x2 == x0 && y2 == y0)
        return false;
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) > 0;
}

void get_hull(std::pair<pii, int>* p, int le, int r, std::vector<int> &ans)
{
    std::map<pii, int> bac;
    for (int i = le; i < r; ++i)
        bac[p[i].first] = p[i].second;
    int mi = le;
    for (int i = le; i < r; ++i)
        if (p[mi] > p[i])
            mi = i;
    pii p1[r - le];
    for (int i = le; i < r; ++i)
        p1[i - le] = p[i].first;
    x0 = p[mi].first.first, y0 = p[mi].first.second;
    std::sort(p1, p1 + r - le, cmp);
    std::stack<pii> st;
    st.push(p[mi].first);
    for (int i = 1; i < r - le; ++i)
    {
        int do_it = 1;
        while (do_it && st.size() >= 2)
        {
            pii midp = st.top();
            st.pop();
            pii lastp = st.top();
            do_it = (long long int)(p1[i].first - lastp.first) * (midp.second - lastp.second) - (long long int)(midp.first - lastp.first) * (p1[i].second - lastp.second) > 0;
            if (!do_it)
                st.push(midp);
        }
        st.push(p1[i]);
    }
    while (st.size() > 0)
    {
        ans.push_back(bac[st.top()]);
        st.pop();
    }
}

int work(int le, int r, std::pair<pii, int>* p, int first)
{
    if (r - le <= 2)
        return 0;
    pii rp[n];
    for (int i = 0; i < n; ++i)
        rp[p[i].second] = p[i].first;
    std::vector<int> hull;
    get_hull(p, le, r, hull);
    std::cout << "? " << hull.size();
    for (int i : hull)
        std::cout << " " << i;
    std::cout << std::endl;
    std::string s;
    std::cin >> s;
    if (s == "Yes")
    {
        int b = work(le, (r + le) / 2, p, 0);
        if (!b)
            b = work((le + r) / 2, r, p, 0);
        if (!b)
        {
            std::vector<int> hull1, hull2;
            get_hull(p, le, (le + r) / 2, hull1);
            get_hull(p, (le + r) / 2, r, hull2);
            int sz1 = hull1.size(), sz2 = hull1.size(), sz = hull.size();
            int d1 = sz1 - 1;
            int yk = sz - 1;
            while (hull1[(d1 + sz1) % sz1] == hull[(yk + sz) % sz])
            {
                --yk;
                --d1;
            }
            int numd2 = hull[(yk + sz) % sz];
            ++d1;
            d1 = ((d1 % sz1) + sz1) % sz1;
            int u1 = 0;
            yk = 0;
            while (hull1[u1 % sz1] == hull[yk % sz])
            {
                ++yk;
                ++u1;
            }
            --u1;
            u1 = ((u1 % sz1) + sz1) % sz1;
            int numu2 = hull[yk % sz];
            int u2, d2;
            for (int i = 0; i < sz2; ++i)
            {
                if (numd2 == hull2[i])
                    d2 = i;
                if (numu2 == hull2[i])
                    u2 = i;
            }
            int yk1 = d1, yk2 = d2;
            int cnt = (d1 - u1 + sz1) % sz1 + (u2 - d2 + sz2) % sz2 - 1;
            pii triangl[cnt];
            triangle[0] = std::mp(d1, d2);
            for (int i = 1; i < cnt; ++i)
            {
                if (yk1 == u1)
                {
                    triangl
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    std::pair<pii, int> p[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &p[i].first.first, &p[i].first.second);
        p[i].second = i;
    }
    std::sort(p, p + n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
        work(0, n, p, 1);
    return 0;
}
