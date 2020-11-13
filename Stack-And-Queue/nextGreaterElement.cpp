// Problem link - https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// NOTE ->> Its very very important to dry run it on simple example like (I/P -> [4 6 1 3 2] -- O/P-> [6 -1 3 -1 -1]) to understand this logic as its not easy to expain it through comments. I repeat veryyyy important. Its super simple that way..trust me.

#include <bits/stdc++.h>
using namespace std;

// Function to return vector of expected output (i.e next greater element for each element in given array)

vector<long long> nextLargerElement(long long nums[], int n)
{

    stack<long long> st;
    vector<long long> resVector;

    // Traverse the given array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Push the element in stack if its empty or its top is greater than current element (i.e nums[i]).See last line of if condition.
        if (st.empty() || st.top() > nums[i])
        {
            if (st.empty())
            {
                resVector.push_back(-1);
            }
            else
            {
                resVector.push_back(st.top());
            }
            st.push(nums[i]);
        }

        // If the current element is greater than top of stack than keep popping out until u find top of stack greater than current element.
        else
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                resVector.push_back(-1);
            }
            else
            {
                resVector.push_back(st.top());
            }
            st.push(nums[i]);
        }
    }

    // Finally, reverse the vector before returning as results will be in reverse order cz we traversed array from back.
    reverse(resVector.begin(), resVector.end());
    return resVector;
}

int main()
{
    int t;
    cin >> t;

    // 't' is for number of test-cases.
    while (t--)
    {

        int n;
        cin >> n;
        long long arr[10000];

        // Taking input array.
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // Calling our function to do the req. task.
        vector<long long> res = nextLargerElement(arr, n);

        // Printing out output
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
