struct node {
    
};
struct SegmentTree {
    int n; 
    vector<node>tree;
    SegmentTree(int _n):n(_n) {
        tree.resize(4*n);
    }
    void add_on_leaf(int cur_node,int val) {

    }
    node merge(node left,node right) { //merge left and right child
        node parent;

    }
    void propagate(int cur_node,int l,int r) {
        //don't forget to update propagate value for child
    }
    void build(int cur_node,int l,int r) {
        if(l==r) {
            //add_on_leaf(cur_node,v[l]);

            return;
        }
        int mid=l+(r-l)/2;
        build(cur_node*2+1,l,mid);
        build(cur_node*2+2,mid+1,r);
        tree[cur_node]=merge(tree[cur_node*2+1],tree[cur_node*2+2]);
    }
    void update(int cur_node,int l,int r,int pos,int val) {
        update(cur_node,l,r,pos,pos,val);
    }
    void update(int cur_node,int l,int r,int b,int e,int val) {
        if(b>r or e<l) return;
        if(b<=l and e>=r) { //update in range
    
            return;
        }
         // if(tree[cur_node].propagate_val>0) { //condition for propagate:
        //     propagate(cur_node,l,r);
        // }
        int mid=l+(r-l)/2;
        update(cur_node*2+1,l,mid,b,e,val);
        update(cur_node*2+2,mid+1,r,b,e,val);
        tree[cur_node]=merge(tree[cur_node*2+1],tree[cur_node*2+2]);
    }
    node query(int cur_node,int l,int r,int b,int e) {
        if(b>r or e<l) { //return out range value
            node temp; return temp;
        }
        if(b<=l and e>=r) return tree[cur_node]; //return in range value
        // if(tree[cur_node].propagate_val>0) { //condition for propagate:
            // propagate(cur_node,l,r);
        // }
        int mid=l+(r-l)/2;
        auto left= query(cur_node*2+1,l,mid,b,e);
        auto right=query(cur_node*2+2,mid+1,r,b,e);
        return(merge(left,right));
    }
};
