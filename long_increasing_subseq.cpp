#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int lis(int i, int a[])
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; ++j)
    {
        if (a[i] > a[j])
            ans = max(ans, lis(j, a) + 1);
    }
    return dp[i] = ans;
}
int longestSubsequence(int n, int a[])
{
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, lis(i, a));
    }
    return ans;
}