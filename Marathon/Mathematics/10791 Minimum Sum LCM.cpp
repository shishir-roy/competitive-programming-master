#include<bits/stdc++.h>
using namespace std;
#define ll long long int


#define MAX 1000000 ///joto porjonto sieve korte cai
#define LMT 1000   /// sqrt(MAX)
#define LEN 300000  ///appx number of primes
#define RNG 100032 ///range for segmentflaged sieve

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

unsigned primeflag[MAX/64+7], segmentflag[RNG/64+7], primes[LEN+7];

/* Generates all the necessary prime numbers and marks them in primeflag[]*/
int tt;
void sieve()
{
    unsigned long long int i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(primeflag, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(primeflag, j);
    j=0;
    primes[j++]=2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(primeflag, i))
            primes[j++] = i;

    tt=j;
}
ll prime_factorize(ll n)
{
	int cnt=0;
	ll ans=0;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < tt && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
        	ll temp=1LL;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                temp*=primes[i];
               /* cout << primes[i] << endl;*/
            }
            cnt++;
            ans+=temp;
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
    	/*cout << n << endl;*/
    	cnt++;
        ans+=n;
    }
    if(cnt==1)
    	ans++;
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int qq=1;
	ll n;
	while(cin >> n)
	{
		if(n==0) return 0;
		ll t=0;
		if(n==1) t=2;
		else 
		t=prime_factorize(n);
		cout << "Case " << qq++ << ": " << t << endl;
	}
}