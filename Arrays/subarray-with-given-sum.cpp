//Problem link- https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, s;
	vector<int> v;

	// 't' is for number of test cases.
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int val;

		// Taking input in a vector(similar to array)
		for (int i = 0; i < n; i++)
		{
			cin >> val;
			v.emplace_back(val);
		}
		int sum = 0;
		int f = 0;
		int i, j;
		for (i = 0, j = 0; i < n && j < n; j++)
		{

			// Adding each element to sum.
			sum += v[j];

			// Removing elements from LHS until 'sum' becomes less or equal to 's'. Can't remove from RHS bcz then 'sum' will definitely be smaller than 's'. Also, can't remove elements from mid as we need subarray (i.e continuous elements).
			while (sum > s)
			{
				sum -= v[i];
				i++;
			}

			// Checking at any instance if 'sum' becomes equal to 's'. We will get our ans then and hence break.
			if (sum == s)
			{
				f = 1;
				break;
			}
		}
		if (f == 1)
		{
			cout << i + 1 << " " << j + 1 << endl; // Use common sense ;-)
		}
		else
			cout << -1 << endl;
		v.clear();
	}
	return 0;
}