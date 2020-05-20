#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mxN=3e4+7;
int a[mxN];
vector<vector<int>>tree(4*mxN);
void build(int cur_node,int l,int r) {
	if(l==r) {
		tree[cur_node].push_back(a[l]);
		return;
	}
	int mid=l+(r-l)/2;
	build(cur_node*2+1,l,mid);
	build(cur_node*2+2,mid+1,r);
	tree[cur_node].resize(tree[cur_node*2+1].size()+tree[cur_node*2+2].size());
	merge(tree[cur_node*2+1].begin(),tree[cur_node*2+1].end(),tree[cur_node*2+2].begin(),tree[cur_node*2+2].end(),tree[cur_node].begin());
}
int query(int cur_node,int l,int r,int b,int e,int k) {
	if(b>r or e<l) return 0;
	if(b<=l and e>=r) {
		return tree[cur_node].end()-upper_bound(tree[cur_node].begin(),tree[cur_node].end(),k);
	}
	int mid=l+(r-l)/2;
	return query(cur_node*2+1,l,mid,b,e,k)+query(cur_node*2+2,mid+1,r,b,e,k);
}
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int q;
	cin>>q;
	build(0,0,n-1);
	while(q--) {
		int l,r,k;
		cin>>l>>r>>k;
		l--,r--;
		cout<<query(0,0,n-1,l,r,k)<<endl;
	}
}
