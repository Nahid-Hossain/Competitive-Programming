struct dsu {
    int n;
    vector<int> p,sz;
    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n,1);
        iota(p.begin(),p.end(), 0);
    }
    inline int find(int u) {
        return (u== p[u] ? u : (p[u]=find(p[u])));
    }
    inline bool merge(int u, int v) {
        u=find(u),v=find(v);
        if(sz[u]<sz[v]) swap(u,v);
        if(u!=v) {
           p[v]=u;
           sz[u]+=sz[v];
           return true;
        }
        return false;
    }
};
