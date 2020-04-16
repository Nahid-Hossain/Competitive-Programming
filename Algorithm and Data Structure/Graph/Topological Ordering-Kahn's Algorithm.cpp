const int mxN=2e5+10;
vector<int>adj[mxN];
vector<int>indegree(mxN,0);
int n;//number of nodes
void topsort() {
    queue<int>q;
    for(int i=0;i<n;i++) {
        if(!indegree[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur_node=q.front();
        //print here
        q.pop();
        for(int u:adj[cur_node]) {
            indegree[u]--;
            if(!indegree[u]) {
                q.push(u);
            }
        }
    }
}
