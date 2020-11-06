// Problem link- https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    // 't' is no. of test-cases.
    while (t--)
    {
        string s;
        string str = "", result = "";
        cin >> s;
        int len = s.size();

        // Traversing string from back and concatinating alphabets until a dot is found.
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] != '.')
            {
                str += s[i];
            }

            // As soon as we encounter a dot, reverse it to make it in original form and push it into result.
            else if (s[i] == '.')
            {
                reverse(str.begin(), str.end());
                result += str;
                result += ".";
                str = "";
            }
        }

        // To reverse last word as we won't encounter dot for it.
        reverse(str.begin(), str.end());

        // Appending it to final result string.
        result += str;
        cout << result << endl;
    }
    return 0;
}