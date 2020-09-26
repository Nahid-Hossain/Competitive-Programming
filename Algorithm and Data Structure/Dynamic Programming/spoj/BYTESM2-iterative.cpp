/* 
    problem link: https://www.spoj.com/problems/BYTESM2/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t; cin>>t;
    while (t--) {
        int h,w; cin>>h>>w;
        int ans=0;
        vector<vector<int>>v(h,vector<int>(w));
        vector<vector<int>>dp(h,vector<int>(w));
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) cin>>v[i][j];
        }
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                dp[i][j]=max({(i-1<0?0:dp[i-1][j]),(i-1<0 or j-1<0?0:dp[i-1][j-1]),(i-1<0 or j+1>=w?0:dp[i-1][j+1])})+v[i][j];
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }
}
