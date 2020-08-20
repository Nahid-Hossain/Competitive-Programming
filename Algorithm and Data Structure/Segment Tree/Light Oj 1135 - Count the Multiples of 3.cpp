#include<bits/stdc++.h>
using namespace std;
struct node {
    int zero_mod3,one_mod3,two_mod3,propagate_val;
    node(): zero_mod3(0),one_mod3(0),two_mod3(0),propagate_val(0) {}
};
struct SegmentTree {
    int n;
    vector<node>tree;
    SegmentTree(int _n):n(_n) {
        tree.resize(4*n);
    }
    void add_on_leave(int cur_node,int val) {
        tree[cur_node].zero_mod3=1;
    }
    node merge(node left,node right) { //merge left and right child
        node parent;
        parent.zero_mod3=left.zero_mod3+right.zero_mod3;
        parent.one_mod3=left.one_mod3+right.one_mod3;
        parent.two_mod3=left.two_mod3+right.two_mod3;
        return parent;
    }
    void process_update(int cur_node,int val) {
        vector<int>a(3);
        a[0]=tree[cur_node].zero_mod3;
        a[1]=tree[cur_node].one_mod3;
        a[2]=tree[cur_node].two_mod3;
        tree[cur_node].zero_mod3=a[(0+val)%3];
        tree[cur_node].one_mod3=a[(1+val)%3];
        tree[cur_node].two_mod3=a[(2+val)%3];
    }
    void propagate(int cur_node,int l,int r) {
        int left=cur_node*2+1;
        int right=cur_node*2+2;
        process_update(left,tree[cur_node].propagate_val);
        process_update(right,tree[cur_node].propagate_val);
        tree[left].propagate_val+=tree[cur_node].propagate_val;
        tree[right].propagate_val+=tree[cur_node].propagate_val;
        tree[cur_node].propagate_val=0;
    }
    void build(int cur_node,int l,int r) {
        if(l==r) {
            add_on_leave(cur_node,1);
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
            process_update(cur_node,val);
            tree[cur_node].propagate_val+=val;
            return;
        }
         if(tree[cur_node].propagate_val>0) { //condition for propagate:
            propagate(cur_node,l,r);
        }
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
        if(tree[cur_node].propagate_val>0) { //condition for propagate:
            propagate(cur_node,l,r);
        }
        int mid=l+(r-l)/2;
        auto left= query(cur_node*2+1,l,mid,b,e);
        auto right=query(cur_node*2+2,mid+1,r,b,e);
        return(merge(left,right));
    }
};
void solve() {
    int n,q; scanf("%d%d",&n,&q);
    SegmentTree segtree(n);
    segtree.build(0,0,n-1);
    while(q--) {
        int type; scanf("%d",&type);
        if(type==0) {
            int l,r; scanf("%d%d",&l,&r);
            segtree.update(0,0,n-1,l,r,1);
        }
        else {
            int l,r; scanf("%d%d",&l,&r);
            node ans=segtree.query(0,0,n-1,l,r);
            printf("%d\n",ans.zero_mod3);
        }
    }
}
int main(int argc, char const *argv[]) {
    int test_case;
    scanf("%d",&test_case);
    for(int tc=1;tc<=test_case;tc++) {
        printf("Case %d:\n",tc);
        solve();
    }
}
