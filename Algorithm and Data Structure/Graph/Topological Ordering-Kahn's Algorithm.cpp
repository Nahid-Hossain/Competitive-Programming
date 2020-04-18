/*
    Description: Topological ordering is a special ordering of edges such that if there is an edge between u-v then u always comes 
    before v. For topological sorting, graph has to be directed acyclic. If there is a cycle in the graph then, topological 
    ordering is not possible. Kahn's algorithm is quite simple algorithm for finding topological ordering. First we will select vertex
    that has 0 indegree. Why so? Well, if a vertex has zero indegree, then this vertex is not dependant on other vertex. We will remove
    the vertex and we will decrease the indegree of it's adjacent by 1. We will continue this process. After finishing, if the count_node
    is less than the total node, then there must have a cycle in that graph. So we will return false  otherwise, we will return 
    true. For lexiographical smallest topological sort, we will use priority_queue instead of queue.
                  
    Test:http://www.lightoj.com/volume_showproblem.php?problem=1003
    Complexity: O(v+e). for lexiographical smallest order (vlogn+e)
*/
const int mxN=2e5+10;
vector<int>adj[mxN];
vector<int>indegree(mxN,0);
vector<int>top_order;
bool topsort(int n) {
    queue<int>q;//use priority queue for lexiographically smallest order
    for(int i=0;i<n;i++) {
        if(!indegree[i]) {
            q.push(i);
        }
    }
    int count_node=0;
    while(!q.empty()) {
        int cur_node=q.front();
        count_node++;
        top_order.push_back(cur_node);
        q.pop();
        for(int u:adj[cur_node]) {
            indegree[u]--;
            if(!indegree[u]) {
                q.push(u);
            }
        }
    }
    return count_node==n;
}
