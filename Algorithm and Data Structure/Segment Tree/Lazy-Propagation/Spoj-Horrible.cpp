#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int  mxN=1e6;
long long a[mxN];
struct node {
	long long sum,propagate_value;
	node():sum(0),propagate_value(0){}
}tree[4*mxN];
void build(int cur_node,int l,int r) {
	if(l==r) {
		tree[cur_node].sum=a[l];
		return;
	}
	long long mid=l+(r-l)/2;
	build(cur_node*2+1,l,mid);
	build(cur_node*2+2,mid+1,r);
	tree[cur_node].sum=tree[cur_node*2+1].sum+tree[cur_node*2+2].sum;
}
void update(int cur_node,int l,int r,int b,int e,int val) {
	if(b>r or e<l) return;
	if(b<=l and e>=r) {
		tree[cur_node].sum+=(r-l+1)*val;
		tree[cur_node].propagate_value+=val;
		return;
	}
	long long mid=l+(r-l)/2;
	update(cur_node*2+1,l,mid,b,e,val);
	update(cur_node*2+2,mid+1,r,b,e,val);
	tree[cur_node].sum=tree[cur_node*2+1].sum+tree[cur_node*2+2].sum;
	tree[cur_node].sum+=(r-l+1)*tree[cur_node].propagate_value;
}
long long query(int cur_node,int l,int r,int b,int e,int carry) {
	if(b>r or e<l) return 0;
	if(b<=l and e>=r) {
		return tree[cur_node].sum+carry*(r-l+1);
	}
	long long mid=l+(r-l)/2;
	carry+=tree[cur_node].propagate_value;
	return query(cur_node*2+1,l,mid,b,e,carry)+query(cur_node*2+2,mid+1,r,b,e,carry);
}
void solve() {
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++) a[i]=0;
	for(int i=0;i<4*mxN;i++) {
		tree[i].sum=0;
		tree[i].propagate_value=0;
	}
	while(q--) {
		int type;
		cin>>type;
		if(type==0) {
			int p,q,v;
			cin>>p>>q>>v;
			p--,q--;
			update(0,0,n-1,p,q,v);
		}
		if(type==1) {
			int p,q;
			cin>>p>>q;
			p--,q--;
			long long ans=query(0,0,n-1,p,q,0);
			cout<<ans<<endl;;
		}
	}
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
    	solve();
    }
}
