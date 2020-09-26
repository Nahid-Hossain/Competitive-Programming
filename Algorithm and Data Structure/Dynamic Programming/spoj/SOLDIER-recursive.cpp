/*
  problem link: https://www.spoj.com/problems/SOLDIER/
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,cost; cin>>n>>cost;
    vector<vector<pair<int,int>>>items(6);
    for(int i=0;i<n;i++) {
        int type,price,quality;
        cin>>type>>price>>quality;
        items[type-1].emplace_back(quality,price);
    }
    vector<vector<int>>dp(6,vector<int>(cost+1,-1));
    function<int(int,int)>recur=[&](int pos,int left) {
        if(pos>=6) return inf;
        if(left<=0) return 0;
        int &cur=dp[pos][left];
        if(cur!=-1) return cur;
        int ans=0;
        for(auto x:items[pos]) {
            ans=max(ans,min(x.first,recur(pos+1,cost-x.second)));
        }
        return cur=ans;
    };
    int ans=recur(0,cost);
    cout<<ans<<endl;
}
