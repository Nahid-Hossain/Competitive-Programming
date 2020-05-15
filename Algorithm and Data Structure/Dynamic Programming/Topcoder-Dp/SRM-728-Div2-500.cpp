#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int mxN=1e4+5;
class IncreasingSequencesEasy {
  public:
  int count(vector <int> a, vector <int> b) {
  	int n=a.size();
  	vector<vector<long long>>dp(n,vector<long long>(mxN,0));
    for(int i=a[0];i<=b[0];i++) dp[0][i]=1;
    for(int i=1;i<n;i++) {
        int l=a[i],r=b[i];
        for(int k=0;k<l;k++) {
        	dp[i][l]+=dp[i-1][k];
        	if(dp[i][l]>=mod) dp[i][l]-=mod;
        }
        for(int j=l+1;j<=r;j++) {
        	dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
        	if(dp[i][j]>=mod) dp[i][j]-=mod;
        }
    }
    long long ans=0;
    for(int i=0;i<mxN;i++) {
        ans+=dp[n-1][i];
      if(ans>=mod) {
         ans-=mod;
      }
    }
    return ans;  
  }
};
