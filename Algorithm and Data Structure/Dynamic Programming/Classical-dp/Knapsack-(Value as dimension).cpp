#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,w;
    cin>>n>>w;
    vector<int>weight(n),value(n);
    for(int i=0;i<n;i++) {
        cin>>weight[i]>>value[i];
    }
    int max_profit=accumulate(value.begin(),value.end(),0);
    vector<vector<int>>dp(2,vector<int>(max_profit+1,inf));
    dp[0][0]=0;
    int cur=0;
    for(int i=1;i<=n;i++) {
        int val=value[i-1];
        int wt=weight[i-1];
        cur^=1;
        for(int j=0;j<=max_profit;j++) {
            if(j<val) {
                dp[cur][j]=dp[cur^1][j];
            }
            else {
                dp[cur][j]=min(dp[cur^1][j],dp[cur^1][j-val]+wt);
            }
        }
    }
    int ans=0;
    for(int val=0;val<=max_profit;val++) {
        if(dp[n&1][val]<=w) {
            ans=max(ans,val);
        }
    }
    cout<<ans<<endl;
}
