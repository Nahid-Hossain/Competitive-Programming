#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,w;
    cin>>n>>w;
    vector<int>value(n),weight(n);
    for(int i=0;i<n;i++) cin>>value[i];
    for(int i=0;i<n;i++) cin>>weight[i];
    int max_value=accumulate(value.begin(),value.end(),0);
    vector<int>dp(max_value+1,inf);
    //dp[i] means minimum weight required to get value exactly i
    dp[0]=0;
    for(int i=1;i<=n;i++) {
        int val=value[i-1];
        int wt=weight[i-1];
        for(int j=max_value-val;~j;j--) {
            dp[j+val]=min(dp[j+val],dp[j]+wt);
        }

    }
    int max_profit=0;
    for(int i=0;i<=max_value;i++) {
        if(dp[i]<=w) {
            max_profit=max(max_profit,i);
        }
    }
    cout<<max_profit<<endl;
}
