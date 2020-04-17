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
