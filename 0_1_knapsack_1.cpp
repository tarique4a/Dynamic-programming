#include <bits/stdc++.h>
using namespace std;

int find(int w, int wt[], int val[], int n, vector<vector<int>> &t)
{
    if (n == 0 || w == 0)
        return 0;
    if (t[n][w] != -1)
        return t[n][w];
    if (wt[n - 1] <= w)
    {
        return t[n][w] = max(val[n - 1] + find(w - wt[n - 1], wt, val, n - 1, t), find(w, wt, val, n - 1, t));
    }
    else if (wt[n - 1] > w)
    {
        return t[n][w] = find(w, wt, val, n - 1, t);
    }
}
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
    return find(w, wt, val, n, t);
}