#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mxN=2e6+5;
class FibonacciDiv2 {
  public:
  int find(int n) {
  	vector<int>fib;
  	fib.push_back(0);
  	fib.push_back(1);
  	int x=1,y=1;
  	for(int i=2;i<mxN;i++) {
  		fib.push_back(x+y);
  		int temp=x;
  		x=y;
  		y=temp+y;
  		if(y>mxN) break;
  	}
  	int L=get_lower(n,fib);
  	int R=*upper_bound(fib.begin(),fib.end(),n);
  	return min(abs(n-L),abs(n-R));
  }
  public:
  	int get_lower(int n,vector<int>&fib) {
  		int low=0,high=fib.size()-1;
  		int ans;
  		while(low<=high) {
  			int mid=(high+low)/2;
  			if(fib[mid]<=n) {
  				ans=fib[mid];
  				low=mid+1;
  			}
  			else {
  				high=mid-1;
  			}
  		}
  		return ans;
  	}

};
