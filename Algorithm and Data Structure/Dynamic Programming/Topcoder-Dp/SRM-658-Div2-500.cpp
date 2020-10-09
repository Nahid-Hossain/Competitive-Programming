#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int mxN=65;
int dp[mxN][mxN][mxN];
int recur(int x,int y,int z) {
    if(x+y+z==0) return 0;
    int &cur=dp[x][y][z];
    if(cur!=-1) return cur;
    vector<int>v={x,y,z};
    int ans=inf;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                set<int>s={i,j,k};
                if(s.size()!=3) continue;
                ans=min(ans,recur(max(v[i]-9,0),max(v[j]-3,0),max(v[k]-1,0))+1);
            }
        }
    }
    return cur=ans;
}
class MutaliskEasy {
  public:
  int minimalAttacks(vector <int> x) {
  	 int a=0,b=0,c=0;
      if(x.size()==1) a=x[0];
      if(x.size()==2) a=x[0],b=x[1];
      if(x.size()==3) a=x[0],b=x[1],c=x[2];
      memset(dp,-1,sizeof(dp));
      int ans=recur(a,b,c);
      return ans;
  }
};
