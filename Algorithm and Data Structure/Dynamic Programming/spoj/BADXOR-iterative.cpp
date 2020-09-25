#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod=100000007;
const int max_xor=1025;
int bin_pow(int a,int b) {
    int res=1;
    while(b) {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        int n,m; cin>>n>>m;
        vector<int>a(n),b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        sort(b.begin(),b.end());
        vector<vector<int>>dp(n+1,vector<int>(max_xor));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<max_xor;j++) {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j^a[i-1]])%mod;
            }
        }
        int bad=0;
        for(int i=0;i<max_xor;i++) {
            if(binary_search(b.begin(),b.end(),i)) {
                bad=(bad+dp[n][i])%mod;
            }
        }
        int res=bin_pow(2,n);
        cout<<"Case "<<tc<<": "<<(res-bad+mod)%mod<<endl;
    }
}
