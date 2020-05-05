const int inf=1e9+7;
const int mxN=1e5+6;
vector<pair<int,int>>adj[mxN];
vector<int>dist(mxN,inf);
void dijkstra(int src) {
    set<pair<int,int>>s;
    s.insert({0,src});
    dist[src]=0;
    while(!s.empty()) {
        int cur_node=s.begin()->second;
        s.erase(s.begin());
        for(auto neighbour:adj[cur_node]) {
            int next=neighbour.first;
            int w=neighbour.second;
            if(dist[cur_node]+w<dist[next]) {
                dist[next]=dist[cur_node]+w;
                s.insert({dist[next],next});
            }
        }
    }
}
