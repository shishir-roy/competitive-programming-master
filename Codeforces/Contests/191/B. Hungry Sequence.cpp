#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

#define MAX 10000000 ///joto porjonto sieve korte cai
#define LMT 3163  /// sqrt(MAX)
#define LEN 664579  ///appx number of primes
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
//    cout << j << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cout << primes[i] << " ";
    return 0;
}
