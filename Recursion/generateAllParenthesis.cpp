// Problem link- https://www.interviewbit.com/problems/generate-all-parentheses-ii/#

/* Problem in brief- 

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()" */

#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all parenthesis.

void solveParenthesis(int open, int close, string result, vector<string> &braces)
{
    // When both kinds of braces are exhausted...result will be having req. string.
    if (open == 0 && close == 0)
    {
        braces.push_back(result);
        return;
    }

    // When open is available..we can use that.
    if (open > 0)
    {
        string op1 = result;
        op1 += '(';
        solveParenthesis(open - 1, close, op1, braces);
    }

    // But, for using close braces there must be more open braces already used. i.e at any instance we can't have more number of closing braces than opening braces.
    if (close > open)
    {
        string op2 = result;
        op2 += ')';
        solveParenthesis(open, close - 1, op2, braces);
    }
    return;
}

// Just a simplr fnction to call recursive function. Not needed though as it could have been done in main func itself. Done because problem link given above required that.

vector<string> generateParenthesis(int A)
{
    int open = A;
    int close = A;
    vector<string> braces;
    string result = "";
    solveParenthesis(open, close, result, braces);
    return braces;
}

int main()
{
    int n;
    cin >> n;
    vector<string> allParenthesis;
    allParenthesis = generateParenthesis(n);
    for (string s : allParenthesis)
    {
        cout << s << " ";
    }
    return 0;
}

// happy coding....