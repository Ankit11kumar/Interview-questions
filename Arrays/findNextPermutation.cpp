// Problem link - https://leetcode.com/problems/next-permutation

// NOTE - This is just a function to find next permutation of an array of numbers. Correct but not running code.

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int size = nums.size();
    int index1, index2;
    index1 = index2 = -1;
    //1- Find break point
    for (int i = size - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index1 = i;
            break;
        }
    }
    //2- If- it doesn't exist- Its last permutation already. Return first permutation in this case.
    if (index1 == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    //3- Else- Swap element at that index with the just greater element from its right.
    for (int i = size - 1; i >= 0; i--)
    {
        if (nums[i] > nums[index1])
        {
            index2 = i;
            break;
        }
    }
    swap(nums[index1], nums[index2]);
    //4- Form the smallest possible combination from all its right element- By     reversing.
    reverse(nums.begin() + index1 + 1, nums.end());
    return;
}
