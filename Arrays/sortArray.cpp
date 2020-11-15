//Problem Link-> https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Approach used- Dutch national flag algorithm.
// Time complexity- O(n) || Space complexity- O(1)

#include <bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main()
{

    int t;
    cin >> t;

    // 't' is no of test cases.
    while (t--)
    {
        int n;
        cin >> n;
        int a[1000];

        // Taking input array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Calling our magical function
        sort012(a, n);

        // Printing out output array.
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// Logic used - 'mid' will make sure that all 0's are at its left and 2's are its right. So, 1's will automatically come to middle.
// Better to dry run it. It's really very very simple!!!!

void sort012(int a[], int n)
{
    int low, mid, high;
    low = mid = 0;
    high = n - 1;
    while (mid <= high)
    {

        // If 'mid' encounters 0, it will swap it with value at 'low'. So, 0's will move towards left.
        if (a[mid] == 0)
        {
            swap(a[low++], a[mid++]);
        }

        // If 1 is encountered by mid, it will simply ignore and move. Hence keeping it in between.
        else if (a[mid] == 1)
        {
            mid++;
        }

        // If 'mid' encounters 2, it will swap it with value at 'high'. So, 2's will move towards right.
        // Twist- Think urself, why the mid is not incremented as in first if condition.
        else
        {
            swap(a[high--], a[mid]);
        }
    }
}