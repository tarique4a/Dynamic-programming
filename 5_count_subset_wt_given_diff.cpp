#include <bits/stdc++.h>
using namespace std;

int util(vector<int> &arr, int i)
{
    int c = 0;
    for (int j = 0; j < i; ++j)
        if (arr[j] == 0)
            c++;
    return c;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int x = (d + sum) / 2;
    if ((d + sum) & 1 || d > sum)
        return 0;
    int mod = 1e9 + 7;
    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = pow(2, util(arr, i));
    for (int j = 1; j <= x; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    return dp[n][x];
}
