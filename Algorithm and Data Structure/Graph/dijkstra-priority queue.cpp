const int inf=1e9+7;
const int mxN=2e5+7;
vector<pair<int,int>>adj[mxN];
vector<int>dist(mxN,inf);
void dijkstra(int src) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()) {
        int cur_node=pq.top().second;
        int cur_dist=pq.top().first;
        pq.pop();
        if(dist[cur_node]!=cur_dist) {
            continue;
        }
        for(auto neighbour:adj[cur_node]) {
            int next=neighbour.first;
            int w=neighbour.second;
            if(dist[cur_node]+w<dist[next]) {
                dist[next]=dist[cur_node]+w;
                pq.push({dist[next],next});
            }
        }
    }
}

//For Printing path we have to know the parent of each node. So we have to maintain another array for keep the parent of each node.
If the distance of destination is infinity, then there is no path between src to destination.

void print_path(int destination) {
    stack<int>path;
    int cur_node=destination;
    if(dist[cur_node]==inf) {
        cout<<-1<<endl;
        return;
    }
    while(cur_node!=-1) {
        path.push(cur_node);
        cur_node=parent[cur_node];
    }
    while(!path.empty()) {
        cout<<path.top()+1<<" ";
        path.pop();
    }
    cout<<endl;
}
