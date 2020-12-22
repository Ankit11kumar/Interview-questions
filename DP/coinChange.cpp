// Problem Link- https://practice.geeksforgeeks.org/problems/coin-change2448/1#

// CONCEPT- Same as unbounded knapsack + subset sum.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(vector<int> S, int m, int n)
    {
        //    long long int dp[m+1][n+1];
        vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1));

        // Initialization of matrix
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - S[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // int arr[m];
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}