#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007


#define MAX 10000 ///joto porjonto sieve korte cai
#define LMT 103   /// sqrt(MAX)
#define LEN 4830  ///appx number of primes
#define RNG 100032 ///range for segmentflaged sieve

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

unsigned primeflag[MAX/64+7], segmentflag[RNG/64+7], primes[1229+7];

/* Generates all the necessary prime numbers and marks them in primeflag[]*/
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
}
ll prime_factorize(ll n)
{
    ll ans=1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < LEN && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            ll cnt=0;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                cnt++;
            }
            ans*=(cnt+1);
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        ans*=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    cout << prime_factorize(6);
    return 0;
}
