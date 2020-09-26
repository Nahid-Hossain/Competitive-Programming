/* 
    problem link: https://www.spoj.com/problems/ACODE/ 
*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mxN=5005;
int dp[mxN];
string s;
int recur(int pos) {
    if(pos==s.size()) return 1;
    int &ret=dp[pos];
    if(ret!=-1) return ret;
    int ways=0;
    if(s[pos]!='0') ways+=recur(pos+1);
    if(pos+1<s.size() and s[pos]!='0') {
        int code=(s[pos]-'0')*10+(s[pos+1]-'0');
        if(code<=26 and code>0) {
            ways+=recur(pos+2);
        }
    }
    return ret=ways;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    while (true) {
        memset(dp,-1,sizeof(dp));
        cin>>s;
        if(s[0]=='0' and s.size()==1) break;
        cout<<recur(0)<<endl;
    }
} 
