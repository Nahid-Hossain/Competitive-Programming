#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    vector<vector<int>>dp(n,vector<int>(3,inf));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>v[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        dp[0][i]=v[0][i];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                if(j==k) {
                    continue;
                }
                dp[i][j]=min(dp[i][j],dp[i-1][k]+v[i][j]);
            }
        }
    }
    int ans=inf;
    for(int i=0;i<3;i++) {
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
}
 
int main(int argc, char const *argv[]) {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        cout<<"Case "<<tc<<": ";
        solve();
    }
}
