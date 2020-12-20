// Problem Link - https://practice.geeksforgeeks.org/problems/rod-cutting/0#

// PS- It's correct but not the best approach and hence to prevent TLE refer to its DP solution. I have done it only to try it out.

#include<bits/stdc++.h>
using namespace std;

int findCost(int n,vector<int>val){
    if(n==0)
    return 0;
    int cost=0;
    int maxCost=INT_MIN;
    for(int i=1;i<=n;i++){
        cost = val[i-1] + findCost(n-i,val);
        if(cost>maxCost){
            maxCost=cost;
        }
    }
    return maxCost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	vector<int>val;
	cin>>t;
	while(t--){
	    cin>>n;
	    int v;
	    for(int i=0;i<n;i++){
	        cin>>v;
	        val.push_back(v);
	    }
	    int result = findCost(n,val);
	    cout<<result<<endl;
	    val.clear();
	}
	return 0;
}