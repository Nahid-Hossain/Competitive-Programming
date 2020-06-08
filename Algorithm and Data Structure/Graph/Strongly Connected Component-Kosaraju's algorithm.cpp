#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=5e5+5;
vector<int>adj[mxN];
vector<int>rev_adj[mxN];
vector<int>component[mxN];
stack<int>dfs_order;
vector<bool>visited(mxN),used(mxN);
int nc=0;
void dfs(int u) {
    visited[u]=true;
    for(int v:adj[u])
        if(!visited[v]) dfs(v);        
    dfs_order.push(u);
}
void scc(int u) {
    component[nc].emplace_back(u);
    used[u]=true;
    for(int v:rev_adj[u])
        if(!used[v]) scc(v);
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        rev_adj[v].emplace_back(u);
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]) dfs(i);
    }
    while(!dfs_order.empty()) {
        int u=dfs_order.top();
        dfs_order.pop();
        if(!used[u]) {
            scc(u);
            ++nc;
        }
    }
    cout<<nc<<endl;
    for(int i=0;i<nc;i++) {
        cout<<component[i].size()<<" ";
        for(int x:component[i]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
