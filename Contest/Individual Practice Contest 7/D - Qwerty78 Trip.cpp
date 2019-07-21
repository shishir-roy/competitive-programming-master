#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
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

#define maxn 1000007

ll bigmod(ll a,ll b,ll m)
{
    /// a^b%m
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(a*ans)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
}
ll modInv(ll a,ll m)
{
    ll x=bigmod(a,m-2,m)%m;
    return x;
}
ll fact[maxn+7];
ll ncr(ll n,ll r,ll p)
{
    ll a = (fact[r]*fact[n-r])%mod;
    ll t = modInv(a,mod);
    ll rr = (fact[n]*t)%mod;
    return rr;
}
ll func(ll a,ll b,ll x,ll y)
{
    return ncr( (x-a)+(y-b) , x-a ,mod );
}
int main()
{

    fact[0]= 1;
    for(ll i=1;i<maxn;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    int tc;
    sf1(tc);
    while(tc--)
    {
        int n,m;
        sf2(n,m);
        int a,b;
        sf2(a,b);

        ll ans = func(1,1,n,m) - ( func(1,1,a,b)*func(a,b,n,m) );
        ans+=mod;
        ans%=mod;
        pf1ll(ans);
    }
    return 0;
}
/*



*/
