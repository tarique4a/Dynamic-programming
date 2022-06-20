#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int arr[], int sum, int n)
{

    bool t[n + 1][sum + 1];
    vector<int> v1;

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
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];

            else
                t[i][j] = t[i - 1][j];

            if (t[i][j] == true)
                v1.push_back(j);
        }
    }
    return v1;
}

int minDifference(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int range = sum;

    vector<int> v;
    v = subsetSum(arr, range, n);

    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {

        mn = min(mn, abs(range - 2 * v[i]));
    }
    return mn;
}