// Problem link- https://practice.geeksforgeeks.org/problems/rod-cutting/0#

// CONCEPT- Concept is same as unbounded knapsack problem. (lna h to mood p h, nhi lna h to phir nhi lna h..baat khtm).

#include<bits/stdc++.h>
using namespace std;

int findCost(int n,vector<int>val,vector<int>rod){
    // Using array is faster but dynamic declaration was showing error on local, hence used vector.
    // int dp[n+1][n+1];                              
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=0;j<=n;j++)
    dp[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            // Max. of (will we take [if we take we might take it again too--> hence dp[i]..and not dp[i-1]] , or will we reject)
            if(rod[i-1]<=j)
                dp[i][j]= max(val[i-1] + dp[i][j-rod[i-1]], dp[i-1][j]);
            else
            // Rejected
            dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	vector<int>val;
	vector<int>rod;
	cin>>t;
	while(t--){
	    cin>>n;
	    int v;
	    for(int i=0;i<n;i++){
	        cin>>v;
	        rod.push_back(i+1);
	        val.push_back(v);
	    }
	    int result = findCost(n,val,rod);
	    cout<<result<<endl;
	    val.clear();
	    rod.clear();
	}
	return 0;
}