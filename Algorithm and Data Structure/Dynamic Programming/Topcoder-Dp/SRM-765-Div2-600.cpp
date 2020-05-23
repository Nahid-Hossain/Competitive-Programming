#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
class Tunnel {
  public:
  int minKeystrokes(vector <string> grid, int r) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>>dp(n,vector<int>(m,inf));
      for(int i=0;i<n;i++) {
      	for(int j=0;j<m;j++) {
      		if(grid[i][j]=='v') {
      			dp[i][j]=0;
      			break;
      		}
      	}
      }
      for(int i=0;i<n-1;i++) {
    	for(int j=0;j<m;j++) {
    		if(grid[i][j]=='v') {
    			if(grid[i+1][j]=='.') {
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				grid[i+1][j]='v';
				}
    			for(int k=j+1;k<=min(j+r,m-1);k++) {
    				if(grid[i][k]=='.') {
    					dp[i][k]=min(dp[i][k],dp[i][k-1]+1);
    					if(grid[i+1][k]=='.') {
    						dp[i+1][k]=min(dp[i+1][k],dp[i][k]);
    						grid[i+1][k]='v';
    					}
    				}
    			}
    			for(int k=j-1;k>=max(j-r,0);k--) {
    				if(grid[i][k]=='.') {
    					dp[i][k]=min(dp[i][k],dp[i][k+1]+1);
    					if(grid[i+1][k]=='.') {
						dp[i+1][k]=min(dp[i+1][k],dp[i][k]);
						grid[i+1][k]='v';
    					}
    				}
    			}
    		}
    	}	
    }
    int ans=inf;
    for(int i=0;i<m;i++) {
    	ans=min(dp[n-1][i],ans);
    }
    return(ans==inf?-1:ans);
  }
};
