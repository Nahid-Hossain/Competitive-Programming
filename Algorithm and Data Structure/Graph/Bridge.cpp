/*
    1. return the vector of indices of edges which are bridges.
    2. handle parallel edges
*/

struct Bridge {
    vector<vector<pair<int,int>>>adj;
    vector<int>start,low;
    vector<int>bridges;
    int n,dfs_timer;
    Bridge(int _n):n(_n),adj(_n),start(_n),low(_n) {}
    void add_edge(int u,int v,int id) {
        adj[u].push_back({v,id});
        adj[v].push_back({u,id});
    }
    vector<int>find_bridges() {
        for(int i=0;i<n;i++) {
            dfs_timer=0;
            if(!start[i]) dfs(i);
        }
        return bridges;
    }
    void dfs(int u,int par=-1) {
        start[u]=low[u]= ++dfs_timer;
        for(auto v:adj[u]) {
            if(v.second==par) continue;
            if(start[v.first]) {
                low[u]=min(low[u],start[v.first]);
            }
            else {
                dfs(v.first,v.second);
                low[u]=min(low[u],low[v.first]);
                if (low[v.first]>start[u]) {
                    bridges.push_back(v.second);
                }
            }
        }
    }
};
