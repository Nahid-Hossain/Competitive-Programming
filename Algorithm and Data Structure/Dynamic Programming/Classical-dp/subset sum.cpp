/*
    Description: This is a quite standard dynamic programming problem. There are n elements and a sum s is given. 
                 You have to tell if there any subset which has sum s;
                 
    Idea: Let's dp[i][s] is true if using first i elements we can make sum s, otherwise false. Now if s=0, then dp[i][s] 
          will always be true cause we can always make sum 0 using empty subset. If i=0 ie. there is no element and s>0 then  we will 
          never be able to make sum s. In that case dp[i][s]=false. In other case,first, we have to see if we can make sum s using first
          i-1 elements. If we can make sum s using first i-1 elements then we also can make sum s using first i elements cause 
          we will not take the ith element, then the sum will remain s till ith element. Otherwise, we will take the ith element and
          check if we can make the remaining sum (s-v[i]) from the previous state. One more thing, if current s is less than ith element 
          then, we can simply copy the status from the previous state.
          
    Test: https:https://www.spoj.com/problems/MAIN72/
    Time Complexity: O(n*sum).
    Space Complexity: O(n*sum).
        
*/

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
