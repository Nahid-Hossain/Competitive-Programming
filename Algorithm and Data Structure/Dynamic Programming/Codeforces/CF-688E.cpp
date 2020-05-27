#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=505;
bool dp[2][mxN][mxN];
int main(int argc, char const *argv[]) {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,sum;
    cin>>n>>sum;
    dp[0][0][0]=true;
    int cur=0;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        cur^=1;
        for(int j=0;j<=sum;j++) {
            for(int k=0;k<=j;k++) {
                dp[cur][j][k]=dp[cur^1][j][k];
                if(j>=x) {
                    dp[cur][j][k]|=dp[cur^1][j-x][k];
                }
                if(k>=x) {
                    dp[cur][j][k]|=dp[cur^1][j-x][k-x];
                }
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<=sum;i++) {
        if(dp[n&1][sum][i]) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<" ";
 
}
