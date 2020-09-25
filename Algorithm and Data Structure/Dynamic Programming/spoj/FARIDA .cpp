#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case; cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        int n; cin>>n;
        if(n==0) {
            cout<<"Case "<<tc<<": "<<0<<endl;
            continue;
        }
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<vector<int>>dp(n,vector<int>(2));
        dp[0][0]=0,dp[0][1]=v[0];
        for(int i=1;i<n;i++) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+v[i];
        }
        cout<<"Case "<<tc<<": "<<max(dp[n-1][0],dp[n-1][1])<<endl;
    }
}
