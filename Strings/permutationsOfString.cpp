//Problem Link- https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    //'t' is for no. of test cases
    while (t--)
    {
        string s;
        cin >> s;

        //Sort the string, to start with lexographically smallest string.
        sort(s.begin(), s.end());
        do
        {
            cout << s << " ";
        } while (next_permutation(s.begin(), s.end())); //Built-in STL function to calculate next permutation of string.
        cout << endl;
    }
    return 0;
}