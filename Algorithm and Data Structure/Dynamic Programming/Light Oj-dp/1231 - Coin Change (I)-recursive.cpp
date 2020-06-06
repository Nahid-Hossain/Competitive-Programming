#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=100000007;
int n,k;
int coin[55],freq[55];
int dp[55][1005];
int coin_change(int idx,int value) {
  if(value==k) return 1;
  if(idx==n) return 0;
  if(dp[idx][value]!=-1) return dp[idx][value];
  long long cnt=0;
  for(int i=0;i<=freq[idx]&&(coin[idx]*i)+value<=k;i++) {
    cnt+=coin_change(idx+1,value+(coin[idx]*i));
    cnt%=mod;
  }
  return dp[idx][value]=cnt;
}
void solve() {
  memset(dp,-1,sizeof(dp));
  cin>>n>>k;
  for(int i=0;i<n;i++) cin>>coin[i];
  for(int i=0;i<n;i++) cin>>freq[i];
  cout<<coin_change(0,0)<<endl;
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
