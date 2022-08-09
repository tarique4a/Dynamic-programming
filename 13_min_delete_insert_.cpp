#include <bits/stdc++.h>
using namespace std;

int minOperations(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < m + 1; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n + m - 2 * dp[n][m];
}