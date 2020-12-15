// Problem link- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[11][11];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        n = w = 10;

        int val[10];
        int wt[10];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];

        //calling method knapSack()
        cout << knapSack(w, wt, val, n) << endl;
    }
    return 0;
}