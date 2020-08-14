struct node {
    int value;
    node() {}
};
struct SegmentTree {
    int n; 
    vector<node>tree;
    SegmentTree(int _n):n(_n) {
        tree.resize(4*n);
    }
    void add_on_leave(int cur_node,int val) {

    }
    void merge(int cur_node,int left,int right) {

    }
    int process_query(int left_val,int right_val) {

    }
    void build(int cur_node,int l,int r) {
        if(l==r) {
            //add_on_leave(cur_node,v[l]);
           
            return;
        }
        int mid=l+(r-l)/2;
        build(cur_node*2+1,l,mid);
        build(cur_node*2+2,mid+1,r);
        merge(cur_node,cur_node*2+1,cur_node*2+2);
    }
    void update(int cur_node,int l,int r,int pos,int val) {
        if(pos>r or pos<l) return;
        if(l==pos and r==pos) {
            // add_on_leave(cur_node,val);

            return;
        }
        int mid=l+(r-l)/2;
        update(cur_node*2+1,l,mid,pos,val);
        update(cur_node*2+2,mid+1,r,pos,val);
        merge(cur_node,cur_node*2+1,cur_node*2+2);
    }
    int query(int cur_node,int l,int r,int b,int e) {
        if(b>r or e<l) return 0; //return inf for minimum 
        if(b<=l and e>=r) return tree[cur_node].value; //return in range value
        int mid=l+(r-l)/2;
        auto left_val= query(cur_node*2+1,l,mid,b,e);
        auto right_val=query(cur_node*2+2,mid+1,r,b,e);
        return(process_query(left_val,right_val));
    }
};
