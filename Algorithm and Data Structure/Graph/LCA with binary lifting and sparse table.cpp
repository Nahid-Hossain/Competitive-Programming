const int mxN=2e5+5;
const int L=18;
vector<int>adj[mxN];
vector<vector<int>>ancestor(mxN,vector<int>(L));
vector<int>level(mxN);
void dfs(int u,int par) {
    ancestor[u][0]=par;
    for(int i=1;i<L;i++) {
        if(ancestor[u][i-1]==-1) {
            ancestor[u][i]=-1;
        } 
        else {
            ancestor[u][i]=ancestor[ancestor[u][i-1]][i-1];
        }
    }
    for(int v:adj[u]) {
        if(v^par) {
            level[v]=level[u]+1;
            dfs(v,u);
 
        }
    }
}
int lca(int u,int v) {
    if(level[u]<level[v]) {
        swap(u,v);
    }
    int diff=level[u]-level[v];
    for(int i=0;i<L;i++) {
        if(diff>>i&1) {
            u=ancestor[u][i];
        }
    }
    if(u==v) return u;
    for(int i=L-1;i>=0;i--) {
        if(ancestor[u][i]^ancestor[v][i]) {
            u=ancestor[u][i];
            v=ancestor[v][i];
        }
    }
    return ancestor[u][0];
}
