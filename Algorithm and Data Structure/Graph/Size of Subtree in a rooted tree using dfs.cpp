const int mxN=2e5+10;
vector<int>adj[mxN];
vector<int>size_of_sub_tree(mxN,0);
void dfs(int u) {
    size_of_sub_tree[u]=1;
    for(int v:adj[u]) {
        if(!size_of_sub_tree[v]) {
            dfs(v);
            size_of_sub_tree[u]+=size_of_sub_tree[v];
        }
    }   
}
