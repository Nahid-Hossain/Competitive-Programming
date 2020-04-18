/*
    Description: Size of subtree in a rooted tree can be found easily using dfs. The size of the subtree of the parent is the total size of
                 the sub tree of it's children. The size of the sub tree of the leaf node is 1. We don't need to use visited array to
                 track which node is visited. If subtree size of node v is not 0, then this node is already visited, so we don't need make
                 dfs call with this node again.
                  
    Test:https://codeforces.com/contest/1337/problem/C
    Complexity: O(v+e)
*/
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
