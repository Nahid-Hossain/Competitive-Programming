#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    vector<int>cost(26);
    for(int i=0;i<26;i++) cin>>cost[i];
    string a,b; cin>>a>>b;
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=m;j++) {
        if(a[i-1]==b[j-1]) {
          dp[i][j]=dp[i-1][j-1]+cost[a[i-1]-'a'];
        }
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
    cout<<dp[n][m]<<endl;
}
