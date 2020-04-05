/*
    Description: If we can color each node using just two colors such that no adjacent node has same color then the graph is called
                 bipartite graph. Checking bipartiteness of a graph is not hard. A simple dfs traversal in enough to check if a graph
                 is bipartite or not. First, if the node is not colored yet, then we will color it using the opposite color of its
                 parent. But if the node has already been colored, then we have to check the color of its parent. If the parent has the 
                 same color then this  graph is not bipartite, hence we will return false and terminate. Otherwise, after visiting all 
                 the nodes, if we can color them using two colors, then the graph is bipartite.
                  
    Test:https://codeforces.com/contest/1296/problem/E1
    Complexity: O(v+e)
*/

const int mxN=1e3+5; //Keep an eye on the node numbers
vector<int>adj[mxN];
vector<int>color(mxN,-1);
bool is_bipartite(int u,int c) {
    color[u]=c;
    for(int v:adj[u]) {
        if(color[v]==-1) {
            if(!is_bipartite(v,c^1)) {
                return false;  
            }
        }
        else if(color[u]==color[v])
              return false;
    }
    return true;
}
