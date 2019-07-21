#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define sf scanf
int seti(int n,int ps)
{
    return ( n|=(1<<ps) );
}
int num_mask[100];
ll pwr[1000007];
void pre()
{
    vector<int>primes;
    primes.push_back(2);
    for(int i=3; i<71; i+=2)
    {
        int f=1;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            primes.push_back(i);
        }
    }

//    for(int x : primes) cout << x << " ";
//    cout << "fine " << endl;
    for(int num=2; num<71; num++)
    {
        int x=0, t=num;
        for(int i=0; i<primes.size(); i++)
        {
            if( t%primes[i] == 0)
            {
                int cnt=0;
                while(t%primes[i] == 0)
                {
                    cnt++;
                    t/=primes[i];
                }
                if(cnt&1)
                {
                    x=seti(x,i);
                }
            }
        }
        num_mask[num]=x;
    }

    num_mask[1]=0;
    pwr[0]=1;
    for(int i=1; i<1000007; i++)
    {
        pwr[i] = (pwr[i-1]*2LL) %mod;
    }
}


int ara[75];
int dp[71][(1<<19)];
ll rec(int ps,int mask)
{
    if(ps>=71)
    {
        if(mask==0) return 1LL;
        return 0LL;
    }
    if(ara[ps]==0) return rec(ps+1,mask);

    if(dp[ps][mask] != -1) return dp[ps][mask];

    long long int ret=0;
    ret = ( pwr[ara[ps]-1] * rec(ps+1,mask) ) % mod;
    ret%=mod;

    ret += ( pwr[ara[ps]-1] * rec(ps+1,mask^num_mask[ps]) ) %mod;
    ret%=mod;

    return dp[ps][mask]=ret;
}
int main()
{
    pre();
    int n;
    sf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int t;
        sf("%d",&t);
        ara[t]++;
    }
    memset(dp,-1,sizeof dp);
    ll temp = rec(1,0) ;
    printf("%d\n",temp-1);
    return 0;
}
