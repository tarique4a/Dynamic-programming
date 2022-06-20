#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int> &A, int target)
{
    int s = 0;
    for (int i = 0; i < A.size(); i++)
        s += A[i];

    int sum = (s + target) / 2;
    if ((s + target) % 2 != 0)
        return 0;
    int n = A.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            zero++;
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (A[i - 1] <= j)
                t[i][j] = (t[i - 1][j - A[i - 1]]) + (t[i - 1][j]);
            else if (A[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    if (sum == 0 || sum == 1)
        return pow(2, zero) * t[n][sum];
    else
        return t[n][sum];
}
