/* 
    problem link: https://www.spoj.com/problems/ALTSEQ/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int>dp(n,1);
    auto sign=[&](int x,int y) {
      if(x>0 and y<0) return true;
      if(x<0 and y>0) return true;
      return false;
    };
    for(int i=0;i<n;i++) {
      for(int j=0;j<i;j++) {
        if(abs(v[j])<abs(v[i]) and sign(v[i],v[j])) {
          dp[i]=max(dp[i],dp[j]+1);
        }
      }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
