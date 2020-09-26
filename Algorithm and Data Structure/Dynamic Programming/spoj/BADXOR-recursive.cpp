/* 
    problem link: https://www.spoj.com/problems/BADXOR/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=100000007;
const int mxN=1005;
int a[mxN],b[mxN];
int dp[mxN][1024];
int n,m;
int recur(int pos,int xor_till) {
  if(pos>=n) {
    if(!binary_search(b,b+m,xor_till)) return 1;
    else return 0;
  }
  int &ret=dp[pos][xor_till];
  if(ret!=-1) return ret;
  int ans=0;
  ans=(ans+recur(pos+1,xor_till^a[pos]))%mod;
  ans=(ans+recur(pos+1,xor_till))%mod;
  return ret=ans;
} 
void solve() {
  memset(dp,-1,sizeof(dp));
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  sort(b,b+m);
  int ans=recur(0,0);
  cout<<ans<<endl;
}
int main() {
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
 
