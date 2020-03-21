const int limit=1e8;
bitset<limit>is_prime;
vector<int> sieve()
{
    //keep an eye on the limit
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<limit;i+=2)
        is_prime[i]=0;
    for(int i=3;i*i<limit;i+=2)
        for(int j=i*i;j<limit;j+=i*2)
            is_prime[j]=0;
    vector<int>prime;
    for(int i=2;i<limit;i++)
        if(is_prime[i])
            prime.push_back(i);
    return prime;
}
