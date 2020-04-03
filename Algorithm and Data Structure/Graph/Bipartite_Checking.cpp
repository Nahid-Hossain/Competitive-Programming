
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
