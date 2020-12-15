// Problem link- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    if (W == 0 || n == 0)
        return 0;
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else
        return knapSack(W, wt, val, n - 1);
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