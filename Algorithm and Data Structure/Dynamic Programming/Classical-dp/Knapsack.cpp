#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=2000005;
long long dp[2][mxN];
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,weight;
    cin>>weight>>n;
    int cur=0;
    for(int i=1;i<=n;i++) {
        cur^=1;
        int v,w;
        cin>>v>>w;
        for(int j=0;j<=weight;j++) {
            if(j<w) {
                dp[cur][j]=dp[cur^1][j];
            }
            else {
                dp[cur][j]=max(dp[cur^1][j],dp[cur^1][j-w]+v);
            }
        }
    }
    cout<<dp[n&1][weight]<<endl;
}
