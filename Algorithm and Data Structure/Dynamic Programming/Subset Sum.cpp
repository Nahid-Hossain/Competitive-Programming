
bool subset_sum(vector<int>&v,int n,int sum) {

	vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            if(j==0) {
                dp[i][j]=true;
            }
            else if(i==0) {
                dp[i][j]=false;
            }
            else if(j<v[i-1]) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                if(dp[i-1][j] or dp[i-1][j-v[i-1]]) {
                    dp[i][j]=true;
                }
                else {
                    dp[i][j]=false;
                }
            }
        
        }
    }
    return dp[n][sum];
}
