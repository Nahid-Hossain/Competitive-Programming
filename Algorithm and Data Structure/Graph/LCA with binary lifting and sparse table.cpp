#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=1005;
const int max_jump=10;
vector<int>adj[mxN];
vector<int>level(mxN);
vector<vector<int>>sparse_table(mxN,vector<int>(max_jump+1,-1));
void dfs(int u,int par) {
    sparse_table[u][0]=par;
    for(int v:adj[u]) {
        if(v!=par) {
            level[v]=level[u]+1;
            dfs(v,u);
        }
    }
} 
void pre_calculate(int n) {
    for(int i=1;i<=max_jump;i++) {
        for(int j=0;j<n;j++) {
            if(sparse_table[j][i-1]!=-1) {
                int x=sparse_table[j][i-1];
                sparse_table[j][i]=sparse_table[x][i-1];
            }
        }
    }
}
int lca(int u,int v) {
    if(level[u]<level[v]) {
        swap(u,v);
    }
    int diff=level[u]-level[v];
    while(diff>0) {
        int x=(int)log2(diff+0.0);
        u=sparse_table[u][x];
        diff-=(1<<x);
    }
    if(u==v) {
        return u;
    }
    for(int i=max_jump;i>=0;i--) {
        if(sparse_table[u][i]!=-1 and sparse_table[v][i]!=-1 and sparse_table[u][i]!=sparse_table[v][i]) {
            u=sparse_table[u][i];
            v=sparse_table[v][i];
        }
    }
    return sparse_table[u][0];
}
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        adj[i].clear();
        level[i]=0;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<=max_jump;j++) {
            sparse_table[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++) {
        int m;
        cin>>m;
        for(int j=1;j<=m;j++) {
            int x;
            cin>>x;
            x--;
            adj[i].emplace_back(x);
        }
    }
    dfs(0,-1);
    pre_calculate(n);
    int q;
    cin>>q;
    while(q--) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        int ans=lca(u,v);
        cout<<ans+1<<endl;
    }

}
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        cout<<"Case "<<tc<<": "<<endl;
        solve();
    }
}
