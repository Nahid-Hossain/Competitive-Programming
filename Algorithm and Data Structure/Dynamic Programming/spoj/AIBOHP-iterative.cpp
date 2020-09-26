/* 
    problem link: https://www.spoj.com/problems/AIBOHP/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i==j) {
                    dp[i][j]=1;
                    continue;
                }
                if(j==i+1) {
                    (s[i]==s[j]?dp[i][j]=2:dp[i][j]=1);
                    continue;
                }
                if(s[i]==s[j]) {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        int lps=dp[0][n-1];
        cout<<n-lps<<endl;
    }
} 
