#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int a[mxN],tree[4*mxN];
void build(int cur_node,int l,int r) {
    if(l==r) {
        tree[cur_node]=a[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(cur_node*2+1,l,mid);
    build(cur_node*2+2,mid+1,r);
    tree[cur_node]=tree[cur_node*2+1]+tree[cur_node*2+2];
}
int query(int cur_node,int l,int r,int b,int e) {
    if(b>r or e<l) return 0;
    if(b<=l and e>=r) return tree[cur_node];
    int mid=l+(r-l)/2;
    return query(cur_node*2+1,l,mid,b,e)+query(cur_node*2+2,mid+1,r,b,e);
}
void update(int cur_node,int l,int r,int b,int e,int val,string type) {
    if(b>r or e<l) return;
    if(b<=l and e>=r) {
        if(type=="remove")
            tree[cur_node]=val;
        else
            tree[cur_node]+=val;
        return;
    }
    int mid=l+(r-l)/2;
    update(cur_node*2+1,l,mid,b,e,val,type);
    update(cur_node*2+2,mid+1,r,b,e,val,type);
    tree[cur_node]=tree[cur_node*2+1]+tree[cur_node*2+2];
}
void solve() {
    memset(a,0,sizeof(a));
    memset(tree,0,sizeof(tree));
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    build(0,0,n-1);
    while(q--) {
        int type;
        scanf("%d",&type);
        if(type==1) {
            int x;
            scanf("%d",&x);
            int ans=query(0,0,n-1,x,x);
            printf("%d\n",ans);
            update(0,0,n-1,x,x,0,"remove");
        }
        if(type==2) {
            int i,v;
            scanf("%d%d",&i,&v);
            update(0,0,n-1,i,i,v,"add");
        }
        if(type==3) {
            int i,j;
            scanf("%d%d",&i,&j);
            int ans=query(0,0,n-1,i,j);
            printf("%d\n",ans);
        }
    }
 
}
int main(int argc, char const *argv[]) {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        printf("Case %d:\n",t);
        solve();
    }
}
