/*  LightOJ: 1153 - Internet Bandwidth
    Max-FLow in undirected graph
    time complexity: O(m*|f|) where f is maxflow
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
struct Edge {
    int u,v,capacity;
};
const int mxN=105;
const int inf=1e9+7;
vector<Edge>edge;
vector<int>adj[mxN];
vector<bool>visited(mxN);
int n,m,s,t;
void add_edge(int u,int v,int c) {
    edge.push_back({u,v,c});
    adj[u].push_back(edge.size()-1);
    edge.push_back({v,u,c});
    adj[v].push_back(edge.size()-1);
}
int dfs(int u,int flow=inf) {
    visited[u]=true;
    if(u==t) return flow;
    for(int idx:adj[u]) {
        int v=edge[idx].v;
        int capacity=edge[idx].capacity;
        if(visited[v] or !capacity) continue;
        int pushed=dfs(v,min(flow,capacity));
        if(pushed>0) {
            edge[idx].capacity-=pushed;
            edge[idx^1].capacity+=pushed;
            return pushed;
        }
    }
    return 0;
}
void solve() {
    cin>>n>>s>>t>>m;
    s--,t--;
    edge.clear();
    for(int i=0;i<n;i++) {
        adj[i].clear();
        visited[i]=false;
    }
    for(int i=0;i<m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        add_edge(u,v,c);
    }
    int max_flow=0;
    while(true) {
        for(int i=0;i<n;i++)
            visited[i]=false;
        int add=dfs(s);
        if(add==0) break;
        max_flow+=add;
    }
    cout<<max_flow<<endl;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        cout<<"Case "<<tc<<": ";
        solve();
    }
}
