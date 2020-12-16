// Problem link- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // To find subset with given sum, returns 1 or 0.
    int isSubsetSum(int N, int arr[], int sum)
    {
        bool dp[N + 1][sum + 1];                // Might show error due to var size array. So, give a constant size to test. eg- dp[100][200];
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
                if (i > 0 && j > 0)
                {
                    if (sum < arr[i - 1])
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[N][sum];
    }

    // To calculate half of total sum of elements of array cz we need to find if any subset exists with that sum(above func does that). Other half will automatically be equal.

    int equalPartition(int N, int arr[])
    {
        int reqSum = 0;
        for (int i = 0; i < N; i++)
        {
            reqSum += arr[i];
        }
        if (reqSum % 2 == 0)
            reqSum = reqSum / 2;
        else
            return 0;
        return isSubsetSum(N, arr, reqSum);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        N = 5;
        int arr[5];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}