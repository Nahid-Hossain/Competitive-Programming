/*
    Description: Topological ordering is a special ordering of edges such that if there is an edge between u-v then u always comes 
    before v. For topological sorting, graph has to be directed acyclic. If there is a cycle in the graph then, topological 
    ordering is not possible. A simple dfs is enough to find the topological sort of a graph. One key observation is, a node will
    always processed after all the node of it's subtree is finished processing. So, after finished processing a node, we will put 
    it in a stack. Therefore, it will be above all the nodes that are directly or indirectly depends on that node.
    If a graph has back edge, then there must be a cycle in the graph. So, if the graph has cycle, then we will return 
    false. We can detect cycle easily by graph coloring. 
                  
    Test:https://codeforces.com/problemset/problem/510/C
    Complexity: O(v+e). for lexiographical smallest order (vlogn+e)
*/

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
