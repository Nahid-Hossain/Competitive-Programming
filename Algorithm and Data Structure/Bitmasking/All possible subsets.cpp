
void all_subset(vector<int>&v,int n) {
    for(int mask=1;mask<(1<<n);mask++) {
        for(int i=0;i<n;i++) {
            if(mask>>i&1) {
                //this element is included in this subset
            }
        }
    }
}
