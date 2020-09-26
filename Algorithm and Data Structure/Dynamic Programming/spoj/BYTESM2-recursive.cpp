/* 
    problem link: https://www.spoj.com/problems/BYTESM2/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=105;
int dp[mxN][mxN];
int v[mxN][mxN];
int h,w;
int recur(int row,int col) {
    if(row<0 or row>=h or col<0 or col>=w) return 0;
    int &ret=dp[row][col];
    if(ret!=-1) return ret;
    int ans=0;
    ans=max(ans,recur(row+1,col)+v[row][col]);
    ans=max(ans,recur(row+1,col+1)+v[row][col]);
    ans=max(ans,recur(row+1,col-1)+v[row][col]);
    return ret=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t; cin>>t;
    while (t--) {
        memset(dp,-1,sizeof(dp));
        cin>>h>>w;
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin>>v[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<w;i++) {
            ans=max(ans,recur(0,i));
        }
        cout<<ans<<endl;
    }
}
