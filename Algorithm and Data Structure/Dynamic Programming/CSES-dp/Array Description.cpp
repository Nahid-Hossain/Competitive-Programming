/*
    Problem Link:https://cses.fi/problemset/task/1746
    Idea: Let's define dp[i][j] as the number of ways we can fill the array till ith indices where value is j. For i=0, we can do it
          separately.If v[i]=0 then we can fill the first position with any value from 1 to m. so dp[0][1...m]=1 if v[0]=0. Otherwise,
          we have only one option to fill the position 0. so dp[i][x]=1 where x=v[0] and all the other position will contain 0. Now for
          other indices, we also have two cases. First, if the value of that indices is not zero, then dp[i][x]=dp[i-1][x-1]+dp[i-1][x]
          +dp[i-1][x+1], where x is the value of that index. Now if the value of that index is zero then, then we will calculate 
          that for all possible x (from 1 to m). We will think that way: "if the value would x, then dp[i][x]==dp[i-1][x-1]+dp[i-1][x]
          +dp[i-1][x+1], where x can be 1 to m. The final answer will be Σdp[n-1][m] where m is [1,m].
    Complexity: O(n*m)
*/


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
