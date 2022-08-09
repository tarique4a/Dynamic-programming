#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int mod = 1e9 + 7;
    int util(int arr[], int i)
    {
        int c = 0;
        for (int j = 0; j < i; ++j)
            if (arr[j] == 0)
                c++;
        return c;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        int dp[n + 1][sum + 1];
        int zcount = 1;
        for (int i = 0; i <= n; i++)
            dp[i][0] = pow(2, util(arr, i));
        for (int j = 1; j <= sum; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
                else
                    dp[i][j] = dp[i - 1][j] % mod;
            }
        }
        return dp[n][sum];
    }

};