struct node {
  // things we should store in each node.
  
};
struct SegmentTree {
  int n; 
  vector<node>tree;
  SegmentTree(int _n):n(_n) {
    tree.resize(4*n);
  }
  node merge(node left,node right) { //merge left and right child
    node parent;

  }
  void propagate(int cur_node,int l,int r) {
    //don't forget to update propagate value for child
    int left=cur_node*2+1;
    int right=cur_node*2+2;
    int mid=l+(r-l)/2;
  }
  void build() {
    int cur_node=0,l=0,r=n-1;
    build(cur_node,l,r);
  }
  void build(int cur_node,int l,int r) {
    if(l==r) {
      //add_on_leaf;

      return;
    }
    int mid=l+(r-l)/2;
    build(cur_node*2+1,l,mid);
    build(cur_node*2+2,mid+1,r);
    tree[cur_node]=merge(tree[cur_node*2+1],tree[cur_node*2+2]);
  }
   void update(int pos,int val) {
    int cur_node=0,l=0,r=n-1;
    update(cur_node,l,r,pos,pos,val);
  }
  void update(int b,int e,int val) {
    int cur_node=0,l=0,r=n-1;
    update(cur_node,l,r,b,e,val);
  }
  void update(int cur_node,int l,int r,int b,int e,int val) {
    if(b>r or e<l) return;
    if(b<=l and e>=r) { //update in range

      return;
    }
    // if(tree[cur_node].propagate_val>0) { //condition for propagate:
    //   propagate(cur_node,l,r);
    // }
    int mid=l+(r-l)/2;
    update(cur_node*2+1,l,mid,b,e,val);
    update(cur_node*2+2,mid+1,r,b,e,val);
    tree[cur_node]=merge(tree[cur_node*2+1],tree[cur_node*2+2]);
  }
   node query(int b,int e) { //keep an eye on the return type
    int cur_node=0,l=0,r=n-1;
    return query(cur_node,l,r,b,e);
  }
  node query(int cur_node,int l,int r,int b,int e) {
    if(b>r or e<l) { //return out range value
       node temp; 
       return temp;
    }
    if(b<=l and e>=r) return tree[cur_node]; //return in range value
    // if(tree[cur_node].propagate_val>0) { //condition for propagate:
    //   propagate(cur_node,l,r);
    // }
    int mid=l+(r-l)/2;
    auto left= query(cur_node*2+1,l,mid,b,e);
    auto right=query(cur_node*2+2,mid+1,r,b,e);
    return(merge(left,right));
  }
  int kth_one(int k) { //return the index of the kth one starting from 0th.
    int cur_node=0,l=0,r=n-1;
    return kth_one(cur_node,l,r,k);
  }
  int kth_one(int cur_node,int l,int r,int k) {
    if(tree[cur_node].sum<=k) return -1; // not enough 1
    if(l==r) return l; //return in range value
    int mid=l+(r-l)/2;
    int left=cur_node*2+1;
    int right=cur_node*2+2;
    // if(tree[left].sum>k) return kth_one(left,l,mid,k);
    // else return kth_one(right,mid+1,r,k-tree[left].sum);
  }
};
};
