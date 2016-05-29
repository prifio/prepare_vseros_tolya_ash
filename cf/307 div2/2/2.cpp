#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> p1, pair<int, int> p2)
{
    return p1 > p2;
}

void sol(string a, string b, string c)
{
    int latera[26] = {0}, laterb[26] = {0}, laterc[26] = {0};
    for (auto i : a)
        ++latera[i - 'a'];
    for (auto i : b)
        ++laterb[i - 'a'];
    for (auto i : c)
        ++laterc[i - 'a'];
    int ans = 0;
    int countb = 0, countc = 0;

    for (int i = 0; i <= 1e5; ++i)
    {
        int isgood = 1;
        int cans = 1e9;

        for (int j = 0; j < 26; ++j)
        {
            if (latera[j] < (long long)laterb[j] * i)
                isgood = 0;
            else if (laterc[j] > 0)
                cans = min((long long)cans, (latera[j] - (long long)laterb[j] * i) / laterc[j]);
        }
        if (isgood && ans < i + cans)
        {
            ans = i + cans;
            countb = i;
            countc = cans;
        }
    }
    for (int i = 0; i < countb; ++i)
    {
        cout << b;
        for (auto j : b)
            --latera[j - 'a'];
    }
    for (int i = 0; i < countc; ++i)
    {
        cout << c;
        for (auto j : c)
            --latera[j - 'a'];
    }
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < latera[i]; ++j)
            printf("%c", 'a' + i);
    printf("\n");
}


int main()
{
    freopen("test.in", "r", stdin);
    string a, b, c;
    while (cin >> a >> b >> c)
    {
        sol(a, b, c);
    }
    return 0;
}
