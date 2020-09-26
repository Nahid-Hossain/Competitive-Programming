/* 
    problem link: https://www.spoj.com/problems/MARTIAN/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    while(true) {
        int n,m; cin>>n>>m;
        if(n==0 and m==0) break;
        vector<vector<int>>a(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        vector<vector<int>>b(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>b[i][j];
            }
        }
        vector<vector<pair<int,int>>>pref_sum(n,vector<pair<int,int>>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                pref_sum[i][j].first=(a[i][j]+(j-1>=0?pref_sum[i][j-1].first:0));
            }
        }
        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                pref_sum[i][j].second=(b[i][j]+(i-1>=0?pref_sum[i-1][j].second:0));
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        function<int(int,int)>recur=[&](int row,int col) {
            if(row<0 or col<0) return 0;
            int &cur=dp[row][col];
            if(cur!=-1) return cur;
            int ans=0;
            ans=max(ans,recur(row,col-1)+pref_sum[row][col].second);
            ans=max(ans,recur(row-1,col)+pref_sum[row][col].first);
            return cur=ans;
        };
        int ans=recur(n-1,m-1);
        cout<<ans<<endl;
    }
} 
