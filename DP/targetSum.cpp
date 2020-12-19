// Problem Link - https://leetcode.com/problems/target-sum/

// PS- It conly contains logic part with proper explaination.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Actually we need to divide array into two parts whose difference is S. (Think !!)
    // So, now if we divide array into such two parts, we already know the sum of both parts of array. Don't we? Its simply sum of whole array.
    // So, we have p1 + p2 = sumofarray
    // And,....... p1 - p2 = S
    // Adding both equations, we get p1 = (S + sumofarray) / 2
    // So, in case S + sumofarray is a odd number...We can't find p1 and hence no answer is possible.
    // One more thing to note is if we encounter any zero in array..just ignore them for the moment and multiply the last answer by 2^numberofZeros (as we can either take them in current set or not).
    // Explaination done...husshhh😅

    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0, zeros = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                zeros++;
        }

        // If the sum of whole array is less than req sum(S), then not possible to find any combination.
        if (S > sum)
            return 0;
        
        if ((sum + S) % 2 == 0)
        {
            int rs = (sum + S) / 2;
            int dp[n + 1][rs + 1];

            for (int i = 0; i < n + 1; i++)
                dp[i][0] = 1;

            for (int j = 1; j < rs + 1; j++)
                dp[0][j] = 0;

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < rs + 1; j++)
                {
                    if (nums[i - 1] == 0)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else if (nums[i - 1] > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
            return pow(2, zeros) * dp[n][rs];
        }
        else
            return 0;
    }
};