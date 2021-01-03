// Problem link- https://practice.geeksforgeeks.org/problems/longest-common-substring/0#

#include <bits/stdc++.h>
using namespace std;

int findLCsub(string s1, string s2, int n, int m)
{
    // int dp[n + 1][m + 1];
    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int res = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > res)
                res = dp[i][j];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        int n, m;
        cin >> n >> m;
        cin >> s1 >> s2;
        int ans = findLCsub(s1, s2, n, m);
        cout << ans << endl;
    }
    return 0;
}