#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    if (n < r)
        return 0;
    if ((n - r) < r)
        r = n - r;
    int dp[r + 1];
    int mod = 1000000007;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % mod;
        }
    }
    return dp[r];
}