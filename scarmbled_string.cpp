#include <bits/stdc++.h>
using namespace std;
bool rec(string s1, string s2, unordered_map<string, int> &um)
{
    int n = s1.size();
    if (s1 == s2)
    {
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    int flag = 0;
    if (um.find(s1 + " " + s2) != um.end())
    {
        return um[s1 + " " + s2];
    }
    for (int k = 1; k < n; k++)
    {
        if (rec(s1.substr(0, k), s2.substr(0, k), um) && rec(s1.substr(k), s2.substr(k), um))
        {
            flag = 1;
        }
        if (flag == 1)
        {
            return true;
        }
        if (rec(s1.substr(0, k), s2.substr(n - k), um) && rec(s1.substr(k), s2.substr(0, n - k), um))
        {
            flag = 1;
        }
        if (flag == 1)
        {
            return true;
        }
    }
    return um[s1 + " " + s2] = flag;
}
bool isScramble(string s1, string s2)
{
    unordered_map<string, int> um;
    return rec(s1, s2, um);
}