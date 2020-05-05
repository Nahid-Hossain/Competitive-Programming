/*
    Description: By using dfs, we can easily find if a graph has cycle or not. First we will mark all nodes by 0. If a node has marked
    by 0, then this node is not visited yet. We will mark all the nodes as 1 that are under processed in the call stack. If a node has 
    finished processing, then we will mark it as 2. During dfs traversal, if we get back to a node that are still in the call stack or 
    other words if visited[u]=1, then this graph must be cyclic.
                 
    Complexity: O(v+e).
*/
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
