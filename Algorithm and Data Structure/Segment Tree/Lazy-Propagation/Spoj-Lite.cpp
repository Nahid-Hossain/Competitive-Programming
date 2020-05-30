#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int const mxN=1e5+5;
struct node {
    int toggle,on;
    node():toggle(0),on(0){}
}tree[4*mxN];
void propagate(int cur_node,int l,int r) {
    tree[cur_node].toggle=0;
    int mid=l+(r-l)/2;
    tree[cur_node*2+1].toggle^=1;
    tree[cur_node*2+2].toggle^=1;
    tree[cur_node*2+1].on=(mid-l+1)-tree[cur_node*2+1].on;
    tree[cur_node*2+2].on=(r-mid)-tree[cur_node*2+2].on;
}
void update(int cur_node,int l,int r,int b,int e) {
    if(b>r or e<l) return;
    if(b<=l and e>=r) {
        tree[cur_node].toggle^=1;
        tree[cur_node].on=(r-l+1)-tree[cur_node].on;
        return;
    }
    if(tree[cur_node].toggle) {
        propagate(cur_node,l,r);
    }
    int mid=l+(r-l)/2;
    update(cur_node*2+1,l,mid,b,e);
    update(cur_node*2+2,mid+1,r,b,e);
    tree[cur_node].on=tree[cur_node*2+1].on+tree[cur_node*2+2].on;
}
int query(int cur_node,int l,int r,int b,int e) {
    if(b>r or e<l) return 0;
    if(b<=l and e>=r) return tree[cur_node].on;
    if(tree[cur_node].toggle) {
        propagate(cur_node,l,r);
    }
    int mid=l+(r-l)/2;
    return query(cur_node*2+1,l,mid,b,e)+query(cur_node*2+2,mid+1,r,b,e);
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int type;
        cin>>type;
        if(type==0) {
            int b,e;
            cin>>b>>e;
            b--,e--;
            update(0,0,n-1,b,e);
        }
        else {
            int b,e;
            cin>>b>>e;
            b--,e--;
            cout<<query(0,0,n-1,b,e)<<endl;
        }  
    }
}
