const int mxN=2e5+10;
vector<int>adj[mxN];
vector<int>visited(mxN,0);
stack<int>top_order;
bool top_sort(int u) {
    visited[u]=1;
    for(int v:adj[u]) {
        if(!visited[v]) {
            if(!top_sort(v)) {
                return false;
            }
        }
        else if(visited[v]==1) {
            return false;
        }
    }
    visited[u]=2;
    top_order.push(u);
    return true;
}
