#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=100000007;
void coin_change() {
  int n,sum;
  cin>>n>>sum;
  vector<int>coin(n),freq(n);
  for(int i=0;i<n;i++) cin>>coin[i];
  for(int i=0;i<n;i++) cin>>freq[i];
  vector<vector<int>>dp(55,vector<int>(1005));
  dp[0][0]=1;
  for(int i=1;i<=n;i++) {
    int x=coin[i-1];
    for(int j=0;j<=sum;j++) {
      for(int k=0;k<=freq[i-1];k++) {
        if(j-k*x>=0) {
          dp[i][j]+=dp[i-1][j-k*x];
          if(dp[i][j]>=mod) {
            dp[i][j]-=mod;
          }
        }
      }
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
