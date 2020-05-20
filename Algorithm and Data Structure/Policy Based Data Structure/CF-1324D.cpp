#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    ordered_set<pair<int,int>>os;
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    long long ans=0;
    for(int i=0;i<n;i++) {
        ans+=os.order_of_key({a[i]-b[i],0});
        os.insert({b[i]-a[i],i});
    }
    cout<<ans<<endl;
}
