#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
const int mxN=205;
string grid[mxN];
int dp[mxN][mxN][2];
int n,m;
int recur(int row,int col,int face) {
    if(row<0 or row>=n or col<0 or col>=m) return 0;
    if(grid[row][col]=='#') return 0;
    int &ret=dp[row][col][face];
    if(ret!=-1) return ret;
    int ans=-inf;
    if(face==1) {
        ans=max(ans,recur(row,col+1,face)+(grid[row][col]=='T'));
        ans=max(ans,recur(row+1,col,face^1)+(grid[row][col]=='T'));
        return ret=ans;
    }
    else {
        ans=max(ans,recur(row,col-1,face)+(grid[row][col]=='T'));
        ans=max(ans,recur(row+1,col,face^1)+(grid[row][col]=='T'));
        return ret=ans;
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t; cin>>t;
    while(t--) {
        memset(dp,-1,sizeof(dp));
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>grid[i];
        cout<<recur(0,0,1)<<endl;
    }
}
