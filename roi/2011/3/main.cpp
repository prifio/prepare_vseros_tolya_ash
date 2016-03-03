#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 9;
const int osn = 27;

struct cikle
{
    long long has;
    int len, sdv;
};

long long d27[2000];

cikle get_cikle(string s)
{
    bool b = false;
    int n = s.length();
    int preff[n];
    preff[0] = 0;
    int now = 0;
    for (int i = 1; i < n; ++i)
    {
        while (now != 0 && s[i] != s[now])
            now = preff[now - 1];
        if (s[i] != s[now])
            preff[i] = 0;
        else
            preff[i] = ++now;
        printf("%d ", preff[i]);
    }

    int len = n - preff[n - 1];
    long long prhsh[len + 1];
    prhsh[0] = 0;
    for (int i = 1; i <= len; ++i)
        prhsh[i] = (prhsh[i - 1] * osn + s[i - 1] - 'A' + 1) % MOD;
    long long res = prhsh[len];
    long long hsh2 = 0;
    int yk = len - 1;
    int sdv = 0;
    while (yk  > 0)
    {
        hsh2 = (hsh2 + (s[yk] - 'A' + 1) * d27[len - yk - 1]) % MOD;
        long long hsh = (prhsh[yk] + hsh2 * d27[yk] % MOD) % MOD;
        if (res > hsh)
        {
            res = hsh;
            sdv = len - yk;
        }
        --yk;
    }
    cikle ans;
    ans.has = res;
    ans.len = len;
    ans.sdv = sdv;
    return ans;
}

int KTO(bool &b, int m1, int a1, int m2, int a2)
{
    if (m1 < m2)
        swap(m1, m2), swap(a1, a2);
    int n1 = m1, n2 = m2;
    while (n1 % n2 > 0)
    {
        n1 %= n2;
        swap(n1, n2);
    }
    if (a1 % n2 != a2 % n2)
    {
        b = false;
        return -1;
    }
    b = true;
    vector<int> v;
    m1 = n1 = m1 / n2;
    m2 = n2 = m2 / n2;
    while (n1 % n2 > 0)
    {
        v.push_back(n1 / n2);
        n1 %= n2;
        swap(n1, n2);
    }
    int k1 = 0, k2 = 1;
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int h = k2;
        k2 = k1 - k2 * v[i];
        k1 = h;
        cout << k1 << k2 << "z\n";
    }
    int h10 = ((m1 * m2 + k2 * m2) % (m1 * m2) + m1 * m2) % (m1 * m2);
    int h01 = ((k1 * m1) % (m1 * m2) + m1 * m2) % (m1 * m2);
    return a1 * h10 % (m1 * m2) + h01 * a2 % (m1 * m2);
}

/*
DCADCAD
BABBABB
ADCADCA
BBABBAB
CADCADC
*/
int main()
{
    d27[0] = 1;
    for (int i = 1; i < 2000; ++i)
        d27[i] = (osn * d27[i - 1]) % MOD;
    int h, w;
    scanf("%d%d", &h, &w);
    string field[h];
    cikle info[h];
    for (int i = 0; i < h; ++i)
    {
        cin >> field[i];
        info[i] = get_cikle(field[i]);
    }
    int len = 1;
    bool b = false;
    while (!b)
    {
        b = true;
        int sdv[len];
        for (int i = 0; i < len; ++i)
            sdv[i] = (info[i + len].sdv + info[i].len - info[i].sdv) % info[i].len;
        for (int i = len; i < h; ++i)
            if (info[i].has != info[i - len].has || info[i].len != info[i - len].len || sdv[i % len] != (info[i].sdv + info[i].len - info[i - len].sdv) % info[i].len)
                b = false;
        if (len)
        {

            for (int i = 0; i )
        }
        ++len;
    }
    --len;
    printf("%d", len);
    int len2 = 1;
    return 0;
}
