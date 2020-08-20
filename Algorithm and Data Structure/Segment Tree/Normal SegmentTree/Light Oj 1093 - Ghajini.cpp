#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int inf=1e9+7;
const int mxN=1e5+5;
vector<int>v(mxN);
struct node {
    int max_value,min_value;
    node(): max_value(0),min_value(inf) {}
};
struct SegmentTree {
    int n;
    vector<node>tree;
    SegmentTree(int _n):n(_n) {
        tree.resize(4*n);
    }
    void add_on_leave(int cur_node,int val) {
        tree[cur_node].max_value=val;
        tree[cur_node].min_value=val;
    }
    node merge(node left,node right) { //merge left and right child
        node parent;
        parent.max_value=max(left.max_value,right.max_value);
        parent.min_value=min(left.min_value,right.min_value);
        return parent;
    }
    void build(int cur_node,int l,int r) {
        if(l==r) {
            //add_on_leave(cur_node,v[l]);
            add_on_leave(cur_node,v[l]);
            return;
        }
        int mid=l+(r-l)/2;
        build(cur_node*2+1,l,mid);
        build(cur_node*2+2,mid+1,r);
        tree[cur_node]=merge(tree[cur_node*2+1],tree[cur_node*2+2]);
    }
    node query(int cur_node,int l,int r,int b,int e) {
        if(b>r or e<l) { //return out range value
            node temp; return temp;
        }
        if(b<=l and e>=r) return tree[cur_node]; //return in range value
        int mid=l+(r-l)/2;
        auto left= query(cur_node*2+1,l,mid,b,e);
        auto right=query(cur_node*2+2,mid+1,r,b,e);
        return(merge(left,right));
    }
};
void solve() {
    int n,d; scanf("%d%d",&n,&d); d--;
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    SegmentTree segtree(n);
    segtree.build(0,0,n-1);
    int ans=0;
    for(int l=0;l<n;l++) {
        int r=min(l+d,n-1);
        node temp=segtree.query(0,0,n-1,l,r);
        ans=max(ans,temp.max_value-temp.min_value);
    }
    printf("%d\n",ans);
}
int main(int argc, char const *argv[]) {
    int test_case;
    scanf("%d",&test_case);
    for(int tc=1;tc<=test_case;tc++) {
        printf("Case %d: ",tc);
        solve();
    }
}
