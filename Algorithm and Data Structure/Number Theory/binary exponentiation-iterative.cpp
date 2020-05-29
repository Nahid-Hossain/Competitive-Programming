const int mod=1e9+7;//be careful
long long bin_pow(long long a,long long b) {
    a%=mod;
    long long res=1;
    while(b) {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
