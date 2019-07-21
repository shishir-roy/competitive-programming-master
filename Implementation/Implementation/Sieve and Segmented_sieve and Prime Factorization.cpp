#include<bits/stdc++.h>
using namespace std;

#define ll long long int
//Problem Statement:
//
//Your are given two integers a and b. You have to find all the primes within range a and b. Here, 1 ≤ a ≤ b ≤ 231-1 and b - a ≤ 105.
//
//Note: You have to handle 1, 2 and even numbers for appropriate case of your own.
//
//Solution:

#define MAX 46656 ///joto porjonto sieve korte cai
#define LMT 216   /// sqrt(MAX)
#define LEN 4830  ///appx number of primes
#define RNG 100032 ///range for segmentflaged sieve

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

unsigned primeflag[MAX/64+7], segmentflag[RNG/64+7], primes[LEN+7];

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

/* Returns the prime-count within range [a,b] and marks them in segmentflag[] */
unsigned long long int segmented_sieve(int a, int b)
{
    unsigned long long int i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;
    memset(segmentflag,0,sizeof segmentflag);
    for(i=1; primes[i]*primes[i]<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segmentflag, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segmentflag, i))
            cnt++;
    return cnt;
}

/*prime factor gula factors vectors a store kore rakhe
complexity:sqrt(n)
*/
void prime_factorize(ll n)
{
    vector<int>factors;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < LEN && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                factors.push_back(primes[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors.push_back(n);
    }
}
int main()
{
    sieve();
    cout << segmented_sieve(1,100) << endl;
    prime_factorize(100);
    return 0;
}
