#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int util(vector<int> &nums, int i)
    {
        int c = 0;
        for (int j = 0; j < i; j++)
            if (nums[j] == 0)
                c++;
        return c;
    }
    int findTargetSumWays(vector<int> &nums, int diff)
    {
        diff = abs(diff);
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if ((sum + diff) & 1 || diff > sum)
            return 0;
        int m = (diff + sum) / 2;
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            dp[i][0] = pow(2, util(nums, i));
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};
