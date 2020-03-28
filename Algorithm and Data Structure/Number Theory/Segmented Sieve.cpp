
const int limit=32000;
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
vector<int> segmented_sieve(int l,int r)
{
	vector<bool>mark(r-l+1,true);
	vector<int>_prime;
	if(l==1)
		mark[0]=false;
	for(int i=0;prime[i]*prime[i]<=r;i++)
	{
		int cur_prime=prime[i];
		for(int j=((l+cur_prime-1)/cur_prime)*cur_prime;j<=r;j+=cur_prime)
		{
			if(j==cur_prime)
				mark[j-l]=true;
			else
				mark[j-l]=false;

		}
	}
	for(int i=l;i<=r;i++)
		if(mark[i-l])
			_prime.push_back(i);
	return _prime;
}
