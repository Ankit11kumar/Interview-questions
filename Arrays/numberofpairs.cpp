//Problem link- https://practice.geeksforgeeks.org/problems/number-of-pairs3422/1

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int binarySearch(int Y[], int n, int element)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (element < Y[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

long long countPairs(int X[], int Y[], int m, int n)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    int threes = 0;
    int fours = 0;
    for (int i = 0; i < n; i++)
    {
        if (Y[i] == 0)
            zeros++;
        if (Y[i] == 1)
            ones++;
        if (Y[i] == 2)
            twos++;
        if (Y[i] == 3)
            threes++;
        if (Y[i] == 4)
            fours++;
    }
    sort(X, X + m);
    sort(Y, Y + n);
    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        if (X[i] == 0)
        {
            continue;
        }
        else if (X[i] == 1)
        {
            res += zeros;
        }
        else if (X[i] == 2)
        {
            int index = binarySearch(Y, n, 2);
            if (index != -1)
            {
                res += n - index;
            }
            res += zeros + ones - threes - fours;
        }
        else
        {
            int index = binarySearch(Y, n, X[i]);
            if (index != -1)
            {
                res += n - index;
            }
            res += zeros + ones;
            if (X[i] == 3)
            {
                res += twos;
            }
        }
    }
    return res;
}
int main()
{
    int X[] = {2, 1, 6};
    int Y[] = {1, 5};
    long long result = countPairs(X, Y, 3, 2);
    cout << result << endl;
}