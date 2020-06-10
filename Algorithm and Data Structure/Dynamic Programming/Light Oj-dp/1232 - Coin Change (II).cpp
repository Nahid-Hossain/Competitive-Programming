#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=100000007;
const int mxN=1e4+5;
int dp[105][mxN];
int pref_sum[105][mxN];
void coin_change() {
  memset(dp,0,sizeof(dp));
  memset(pref_sum,0,sizeof(pref_sum));
  int n,sum;
  cin>>n>>sum;
  vector<int>coin(n);
  for(int i=0;i<n;i++) cin>>coin[i];
  dp[0][0]=1;
  for(int i=1;i<=n;i++) {
      int x=coin[i-1];
    for(int j=0;j<=sum;j++) {
        pref_sum[i][j]=dp[i-1][j];
        if(j-x>=0) {
            pref_sum[i][j]+=pref_sum[i][j-x];
            if(pref_sum[i][j]>=mod) {
                pref_sum[i][j]-=mod;
            }
        }
        dp[i][j]=pref_sum[i][j];
    }
  }
   
  cout<<dp[n][sum]<<endl;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
      cout<<"Case "<<tc<<": ";
      coin_change();
    }
}
