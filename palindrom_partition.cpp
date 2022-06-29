#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
bool ispalin(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (ispalin(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int lt, rt;
        if (dp[i][k] != -1)
            lt = dp[i][k];
        else
            lt = solve(s, i, k);
        if (dp[k + 1][j] != -1)
            rt = dp[k + 1][j];
        else
            rt = solve(s, k + 1, j);
        int temp = 1 + lt + rt;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int palindromicPartition(string str)
{
    memset(dp, -1, sizeof(dp));
    return solve(str, 0, str.size() - 1);
}