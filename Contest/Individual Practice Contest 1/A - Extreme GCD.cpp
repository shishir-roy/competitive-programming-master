#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007


#define MAX 10050 ///joto porjonto sieve korte cai
#define LMT 105   /// sqrt(MAX)
#define LEN 1233  ///appx number of primes
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
    primes[j]
    primes[j++]=2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(primeflag, i))
            primes[j++] = i;
}

ll ncr[10007][10];
void bio()
{
    for(int i=1;i<10007;i++)
    {
        ncr[i][0]=ncr[i][i]=1;
        ncr[i][1]=i;
        for(int j=2;j<10;j++)
        {
            ncr[i][j] = ( ncr[i-1][j] + ncr[i-1][j-1] )%mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        cin >> n;
        int ara[n+7];
        int mx=0;
        for(int i=0;i<n;i++)
        {
            cin >> ara[i];
            mx=max(mx,ara[i]);
        }
        int sq= sqrt(mx);
        sq+=5;
        ll ans=ncr[n][4];
        for(int i=0;i<1233 && primes[i]<=sq;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(ara[j]%primes[i]==0)
                {
                    ara[j]=-1;
                    cnt++;
                }
            }

        }
    }
    return 0;
}
