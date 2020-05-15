/*
    Problem Link: https://community.topcoder.com/stat?c=problem_statement&pm=14809&rd=17064&rm=330921&cr=40543852
    Idea: Let dp[i][j] means the total numbers of increasing subsequence till index i starting with j and a[i]<=j<=b[i] must be hold.
          Let a[i]=L and b[i]=R. Now we can calculate for index 0 separately.dp[0][j]=1 for all j from L to R inclusive. Now for other 
          indices, if we start our increasing subsequence with the value L, then dp[i][L]=sum of(dp[i-1][1...L-1] since the subsequence
          must be strictly increasing. Now the subsequence can start from any value from L to R. If we know dp[i][L] then,
          dp[i][L+1]=dp[i][L]+dp[i-1][L] because dp[i][L+1]=sum of(dp[i-1][1...L] and dp[i][L]=sum of(dp[i-1][1...L-1]).So 
          dp[i]L+1]=dp[i][L]+dp[i-1][L]. The final answer will be sum of(dp[n-1][0...max(R)].
    Complexity: O(n*max(R).
*/
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
