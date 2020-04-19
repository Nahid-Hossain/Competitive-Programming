const int mxN=2e5+10;
vector<int>adj[mxN];
vector<int>visited(mxN,0);
vector<int>parent(mxN);
bool has_cycle(int u) {
    visited[u]=1;
    for(int v:adj[u]) {
        if(!visited[v]) {
            parent[v]=u;
            if(!has_cycle(v)) {
                return false;
            }
        }
        else if(visited[v]==1 and v!=parent[u]) {
            return false;
        }
    }
    visited[u]=2;
    return true;
}
