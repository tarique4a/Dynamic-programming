#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length() + 1, m = str2.length() + 1;
    int dp[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n - 1, j = m - 1;
    string res = "";
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            res += (str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                res += (str1[i - 1]);
                i--;
            }
            else
            {
                res += (str2[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        res += (str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        res += (str2[j - 1]);
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}