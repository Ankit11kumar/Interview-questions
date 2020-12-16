// Problem link- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // To find subset with given sum, returns 1 or 0.
    int isSubsetSum(int N, int arr[], int sum)
    {
        if (N == 0 && sum == 0)
            return 1;
        if (N == 0 || sum == 0)
            return 0;
        if (sum > arr[N - 1])
            return isSubsetSum(N - 1, arr, sum) || isSubsetSum(N - 1, arr, sum - arr[N - 1]);
        else
            return isSubsetSum(N - 1, arr, sum);
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