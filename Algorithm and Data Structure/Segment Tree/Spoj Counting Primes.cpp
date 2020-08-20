#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=1e4+5;
const int limit=1e6+10; //keep an eye on the limit
bitset<limit>is_prime;
vector<int>v(mxN);
void sieve() {
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<limit;i+=2)
        is_prime[i]=0;
    for(int i=3;i*i<limit;i+=2) {
        if(is_prime[i]) {
            for(int j=i*i;j<limit;j+=i*2)
                is_prime[j]=0;
        }
    }   
}
struct node {
    int prime_count,propagate_val;
    node(): prime_count(0),propagate_val(0) {}
};
struct SegmentTree {
    int n; 
    vector<node>tree;
    SegmentTree(int _n):n(_n) {
        tree.resize(4*n);
    }
    void add_on_leave(int cur_node,int x) {
        if(is_prime[x]) tree[cur_node].prime_count=1;
    }
    node merge(node left,node right) { //merge left and right child
        node parent;
        parent.prime_count=left.prime_count+right.prime_count;
        return parent;
    }
    void propagate(int cur_node,int l,int r) {
        int x=tree[cur_node].propagate_val;
        int left=cur_node*2+1;
        int right=cur_node*2+2;
        int mid=l+(r-l)/2;
        if(is_prime[x]) {
            tree[left].prime_count=(mid-l+1);
            tree[right].prime_count=(r-mid);
            tree[left].propagate_val=x;
            tree[right].propagate_val=x;
        }
        else {
            tree[left].prime_count=0;
            tree[right].prime_count=0;
            tree[left].propagate_val=x;
            tree[right].propagate_val=x;
        }
        tree[cur_node].propagate_val=0;
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
    void update(int cur_node,int l,int r,int pos,int val) {
        update(cur_node,l,r,pos,pos,val);
    }
    void update(int cur_node,int l,int r,int b,int e,int x) {
        if(b>r or e<l) return;
        if(b<=l and e>=r) { //update in range
            if(is_prime[x])
                tree[cur_node].prime_count=(r-l+1);
            else tree[cur_node].prime_count=0;
            tree[cur_node].propagate_val=x;   
            return;
        }
         if(tree[cur_node].propagate_val>0) { //condition for propagate:
            propagate(cur_node,l,r);
        }
        int mid=l+(r-l)/2;
        update(cur_node*2+1,l,mid,b,e,x);
        update(cur_node*2+2,mid+1,r,b,e,x);
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
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>v[i];
    sieve();
    SegmentTree segtree(n);
    segtree.build(0,0,n-1);
    while(q--) {
        int type; cin>>type;
        if(type==0) {
            int l,r,val; cin>>l>>r>>val;
            l--,r--;
            segtree.update(0,0,n-1,l,r,val);
        }
        else {
            int l,r; cin>>l>>r;
            l--,r--;
            node ans=segtree.query(0,0,n-1,l,r);
            cout<<ans.prime_count<<endl;
        }
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int test_case;
    cin>>test_case;
    for(int tc=1;tc<=test_case;tc++) {
        cout<<"Case "<<tc<<":"<<endl;
        solve();
    }
}
