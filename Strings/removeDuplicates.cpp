// Problem Link - https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

string removeDups(string);

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // 't' is no of test-cases
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << removeDups(s) << "\n";
    }

    return 0;
}

// LOGIC- Traverse through string and append the character to result string 'res' if its not present in set and then insert it in set too. Else, just ignore that character if found in set as it means it has already been occurred before.
// FYI- set only contains unique characters.

string removeDups(string S)
{
    unordered_set<char> us;
    string res = "";
    for (char ch : S)
    {
        if (us.find(ch) == us.end())
        {
            res += ch;
            us.insert(ch);
        }
    }
    return res;
}