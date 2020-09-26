/* 
    problem link: https://www.spoj.com/problems/SAMER08C/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
bool solve() {
    int n,m; cin>>n>>m;
    if(n+m==0) return false;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    vector<int>row_value(n);
    for(int i=0;i<n;i++) {
        vector<vector<int>>col_dp(m,vector<int>(2));
        col_dp[0][0]=0,col_dp[0][1]=grid[i][0];
        for(int j=1;j<m;j++) {
            col_dp[j][0]=max(col_dp[j-1][0],col_dp[j-1][1]);
            col_dp[j][1]=col_dp[j-1][0]+grid[i][j];
        }
        row_value[i]=max(col_dp[m-1][0],col_dp[m-1][1]);
    }
    vector<vector<int>>row_dp(n,vector<int>(2));
    row_dp[0][0]=0,row_dp[0][1]=row_value[0];
    for(int i=1;i<n;i++) {
        row_dp[i][0]=max(row_dp[i-1][0],row_dp[i-1][1]);
        row_dp[i][1]=row_dp[i-1][0]+row_value[i];
    }
    cout<<max(row_dp[n-1][0],row_dp[n-1][1])<<endl;
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    while(true) {
        if(!solve()) break;
    }
