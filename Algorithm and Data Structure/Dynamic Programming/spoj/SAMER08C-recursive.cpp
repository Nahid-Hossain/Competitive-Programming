#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mxN=1e5+5;
vector<int>dp(mxN);
int recur(vector<int>&v,int pos) {
    if(pos>=v.size()) return 0;
    if(dp[pos]!=-1) return dp[pos];
    int x=recur(v,pos+1);
    int y=recur(v,pos+2)+v[pos];
    return dp[pos]=max(x,y);
}
bool solve() {
    int n,m; cin>>n>>m;
    if(n+m==0) return false;
    for(int i=0;i<max(n,m);i++) dp[i]=-1;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    vector<int>row_dp(n);
    for(int i=0;i<n;i++) {
        for(int i=0;i<m;i++) dp[i]=-1;
        row_dp[i]=recur(grid[i],0);
    }
    for(int i=0;i<n;i++) dp[i]=-1;
    cout<<recur(row_dp,0)<<endl;
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    while(true) {
        if(!solve()) break;
    }
}
