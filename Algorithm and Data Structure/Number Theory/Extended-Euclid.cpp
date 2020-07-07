template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
    if(b==0) {
        x=1,y=0;
        return a;
    }
    T x1,y1;
    T gcd=extended_euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return gcd;
}
