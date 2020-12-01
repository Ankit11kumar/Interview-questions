// Problem link- https://practice.geeksforgeeks.org/problems/subsets/0#

#include <bits/stdc++.h>
using namespace std;

// Before writing out this function..try to build it's recursion tree. After that it will be soooooo easy.
void solve(vector<int> ip, vector<int> op, set<vector<int>> &s)
{
    // End case-> Whenever we reach till leaf of tree, where we have no input elements to consider, we will be having one subset of integers in op.
    if (ip.size() == 0)
    {
        s.insert(op);
        return;
    }

    // Initialized two vectors with previous output. Why 2? cz we have two choices for each element. Include it in output or not.
    vector<int> op1 = op;
    vector<int> op2 = op;

    // So, here i included it in output.
    op2.push_back(ip[0]);

    // Input vector size will be reduced in each recursive call as for one of of its element we made a choice.
    ip.erase(ip.begin(), ip.begin() + 1);

    // Calling again with output in which we didn't included the input element i.e.op1.
    solve(ip, op1, s);

    // Calling again with output in which we included the input element i.e.op2.
    solve(ip, op2, s);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    vector<int> ip;
    cin >> t;
    while (t--)
    {
        // All standard stuff of taking input.
        int v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            ip.push_back(v);
        }

        // Sorting input vector so that numbers in each vector of set of vectors will be in sorted way.
        sort(ip.begin(), ip.end());
        set<vector<int>> s;
        vector<int> op;

        // This is the only thing which you should focus on. Rest all is very easy.
        solve(ip, op, s);

        // Don't worry much about below code. It was just to print the result in particular way.
        for (auto i = s.begin(); i != s.end(); i++)
        {
            // Picking one vector from set of vectors s to op.
            op = *i;
            int ops = op.size();

            // Printing out all elements of op with required braces.
            cout << "(";
            for (int j = 0; j < ops; j++)
            {
                if (j == ops - 1)
                {
                    cout << op[j];
                    break;
                }
                cout << op[j] << " ";
            }
            cout << ")";
        }
        cout << endl;

        // Clearing out vectors for next test case...very very important....i forget it most of the times.
        ip.clear();
        op.clear();
    }
    return 0;
}