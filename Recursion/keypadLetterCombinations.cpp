// Problem link- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Only logic part implemented- Don't run it directly. Easy to understand but hard to explain through comments..lol.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> v{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string digits, vector<string> &result, string s, int index)
    {
        if (index == digits.size())
        {
            result.push_back(s);
            return;
        }
        int rd = digits[index] - '0';
        for (int i = 0; i < v[rd].size(); i++)
        {
            s.push_back(v[rd][i]);
            solve(digits, result, s, index + 1);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        string s = "";
        solve(digits, result, s, 0);
        return result;
    }
};