#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=1e9+7;
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>>dp(n,vector<int>(m+1,0));
    if(v[0]==0) {
        fill(dp[0].begin(),dp[0].end(),1);
    }
    else {
        int x=v[0];
        dp[0][x]=1;
    }
    for(int i=1;i<n;i++) {
        int x=v[i];
        if(x) {
            for(int k:{x-1,x,x+1}) {
                if(k>=1 and k<=m) {
                    dp[i][x]+=dp[i-1][k];
                }
                if(dp[i][x]>=mod) {
                    dp[i][x]-=mod;
                }
            }
        }
        else {
            for(int j=1;j<=m;j++) {
                for(int k:{j-1,j,j+1}) {
                    if(k>=1 and k<=m) {
                        dp[i][j]+=dp[i-1][k];
                    }
                    if(dp[i][j]>=mod) {
                        dp[i][j]-=mod;
                    }
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=m;i++) {
        ans+=dp[n-1][i];
        if(ans>=mod) {
            ans-=mod;
        }
    }
    cout<<ans<<endl;
}
