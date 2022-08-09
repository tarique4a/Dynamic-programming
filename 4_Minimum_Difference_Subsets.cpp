#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    int range = 0;
    for (int i = 0; i < n; ++i)
        range += A[i];
    bool dp[n + 1][range + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= range; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j <= range / 2; j++)
    {
        if (dp[n][j])
        {
            ans = min(ans, range - 2 * j);
        }
    }
    return ans;
}