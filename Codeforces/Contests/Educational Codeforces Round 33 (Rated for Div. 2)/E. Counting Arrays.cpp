#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define DB                    cout<<"****"<<endl;
#define mod                   1000000007
#define inf                   INT_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)
#define maxn 1000557

int spf[maxn];
void sieve()
{
    for(int i=2; i<maxn; i++) spf[i] = i;
    for(int i=2; i<maxn; i+=2) spf[i] = 2;
    for(int i=3; i*i<maxn; i+=2)
    {
        if(spf[i]==i)
        {
            for(int j=i*i,k=2*i; j<maxn; j+=k)
            {
                if(spf[j] == j) spf[j]=i;
            }
        }
    }
}

ll bigmod(ll b,ll p)
{
    ll temp=1;
    while(p>0)
    {
        if(p&1) temp = (temp*b)%mod;
        p>>=1;
        b = (b*b)%mod;
    }
    return temp;
}

ll fac[1000507];
void pre()
{
    fac[0]=1;
    for(ll i=1; i<1000507; i++)
    {
        fac[i] = (fac[i-1]*i) % mod;
    }
}

ll ncr(ll n,ll r)
{
    ll nu=fac[n];
    ll de = ( fac[r] * fac[n-r] ) % mod ;
    nu = nu * bigmod(de,mod-2) ;
    return nu%mod;
}

int y;
ll  prime_factor(int n)
{
    ll ans=1;
    while(n != 1)
    {
        int x=spf[n];
        int cnt=0;
        while(n%x==0)
        {
            n/=x;
            cnt++;
        }
        ans*=ncr(y+cnt-1,cnt);
        ans%=mod;
        ans+=mod;
    }
    return ans%mod;
}

void solve(int x)
{
    ll ans = prime_factor(x);
    cout << ans%mod << endl;
    ll t = bigmod(2,y-1)  ;
    ans*=t;
    ans%=mod;
    pf1ll( (ans+mod) % mod );
}
int main()
{
    sieve();
    pre();
    int q;
    sf1(q);
    while(q--)
    {
        int x;
        sf2(x, y);
        solve(x);
    }
    return 0;
}
/*



*/
