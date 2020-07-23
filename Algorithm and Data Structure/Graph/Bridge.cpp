#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=10005;
vector<int>adj[mxN];
vector<int>visited(mxN),start(mxN),low(mxN);
vector<pair<int,int>>bridge;
int dfs_timer=0;
void dfs(int u,int par=-1) {
    visited[u]=true;
    start[u]=low[u]=++dfs_timer;
    for(int v:adj[u]) {
        if(v==par) continue;
        if(!visited[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>start[u]) {
                int tu=u,tv=v;
                if(tu>tv) swap(tu,tv);
                bridge.push_back({tu,tv});
            }
        }
        else {
            low[u]=min(low[u],start[v]);
        }
    }
}
void solve() {
    int n;
    scanf("%d",&n);
    if(n==0) {
        printf("0 critical links\n");
        return;
    }
    bridge.clear();
    for(int i=0;i<=n;i++) {
        adj[i].clear();
        start[i]=0;
        low[i]=0;
        visited[i]=false;
    }
    for(int i=0;i<n;i++) {
        int u; char s[20];
        // scanf("%d%s",&u,&s);
        scanf("%d",&u);
        scanf("%s",&s);
        int m=atoi(&s[1]);
        for(int j=0;j<m;j++) {
            int v;
            scanf("%d",&v);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }
    dfs_timer=0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    sort(bridge.begin(),bridge.end());
    printf("%d critical links\n",bridge.size());
    for(auto x:bridge) {
        printf("%d - %d\n",x.first,x.second);
    }
}
int main(int argc, char const *argv[]) {
    int test_case;
    scanf("%d",&test_case);
    for(int tc=1;tc<=test_case;tc++) {
        printf("Case %d:\n",tc);
        solve();
    }
}
