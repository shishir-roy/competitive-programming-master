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

#define maxn 200007

ll fac[maxn],inv[maxn];
ll bigmod(ll b,ll p)
{
    ll ans=1;
    while(p)
    {
        if(p&1) ans = (ans*b) % mod ;
        p>>=1;
        b = (b*b) % mod;
    }
    return ans%mod;
}

void pre()
{
    fac[0] = 1;
    inv[0] = 1;
    for(ll i=1;i<maxn;i++)
    {
        fac[i] = (fac[i-1]*i) % mod;
        inv[i] = ( inv[i-1] * bigmod(i,mod-2) ) % mod;
    }
}

ll ncr(ll n,ll r)
{
    ll nu = ( fac[n] * inv[r] ) % mod;
    ll t = ( nu*inv[n-r] ) % mod;
    return t;
}

int main()
{
    pre();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans = ncr(2LL*n-1,n-1) % mod;
    ans*=2LL;
    ans-=n;
    cout << (ans+mod) % mod << endl;
    return 0;
}
/*



*/
