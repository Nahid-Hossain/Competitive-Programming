/*
    Description: prime vector contains all the primes up to limit n.
                 is_prime[i] is true if i is a prime.
    Test: https://www.spoj.com/problems/TDPRIMES/
    Complexity: O(n log log n)
    Time taken for 100'000'000 is approx 0.8 s. Runs 30% faster if only odd indices are stored.
        
*/

const int limit=1e8;
bitset<limit>is_prime;
vector<int>prime;
void sieve()
{
    //keep an eye on the limit
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<limit;i+=2)
        is_prime[i]=0;
    for(int i=3;i*i<limit;i+=2)
        for(int j=i*i;j<limit;j+=i*2)
            is_prime[j]=0;
    for(int i=2;i<limit;i++)
        if(is_prime[i])
            prime.push_back(i);
}
