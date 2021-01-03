#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

string printLcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input

        cout << printLcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// function to find longest common subsequence

string printLcs(int x, int y, string s1, string s2)
{

    // int dp[x + 1][y + 1];
    vector<vector<long long int>> dp(x + 1, vector<long long int>(y + 1));
    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= y; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Using backtracking to print lcs
    string res = "";

    int i = x, j = y;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
