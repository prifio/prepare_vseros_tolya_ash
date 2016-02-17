#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int bal[n + 1];
    bal[0] = 0;
    map<char, int> mp;
    mp['('] = 1;
    mp[')'] = -1;
    for (int i = 0; i < n; ++i)
        bal[i + 1] = bal[i] + mp[s[i]];
    long long ans = 1;
    int yk = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += n + 1 - i;
        while (yk < i || bal[yk] > 0)
            ++yk;
        ans += yk - i;
    }
    cout << ans;
    return 0;
}
/*(())
(][())
(]([))
(]()[)
((][))
((])[)
(()][)
*/
