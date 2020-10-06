#include<bits/stdc++.h>
using namespace std;
class RepeatStringEasy {
  public:
  int maximalLength(string s) {
    int n=s.size();
    auto get=[&](string &a,string&b) {
        int n=a.size(), m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(a[i-1]==b[j-1]) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    };
    int best=0;
    for(int i=0;i<n;i++) {
        string a="",b="";
        for(int j=0;j<i;j++) a+=s[j];
        for(int j=i;j<n;j++) b+=s[j];
        best=max(best,get(a,b));
    
    }
    return 2*best;
  }
};
