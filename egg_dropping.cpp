#include <bits/stdc++.h>
using namespace std;

int dp[201][201];
int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int ans = INT_MAX;
    for (int k = 1; k < f; ++k)
    {
        int lo, hi;
        if (dp[e - 1][k - 1] != -1)
            lo = dp[e - 1][k - 1];
        else
            lo = solve(e - 1, k - 1);
        if (dp[e][f - k] != -1)
            hi = dp[e][f - k];
        else
            hi = solve(e, f - k);

        int temp = 1 + max(lo, hi);
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}
int eggDrop(int e, int f)
{
    memset(dp, -1, sizeof(dp));
    return solve(e, f);
}