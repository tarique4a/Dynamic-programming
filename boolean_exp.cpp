#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
int mod = 1003;
int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return false;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    string t = to_string(i);
    t.push_back(' ');
    t.append(to_string(j));
    t.push_back(' ');
    t.append(to_string(isTrue));
    if (m.find(t) != m.end())
        return m[t];

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);
        if (s[k] == '&')
        {
            if (isTrue)
                ans += lt * rt;
            else
                ans += lt * rf + lf * rf + lf * rt;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += lt * rt + lf * rt + lt * rf;
            else
                ans += lf * rf;
        }
        else
        {
            if (isTrue)
                ans += lt * rf + lf * rt;
            else
                ans += lt * rt + lf * rf;
        }
    }
    return m[t] = ans % mod;
}

int countWays(int N, string S)
{
    m.clear();
    return solve(S, 0, N - 1, true);
}