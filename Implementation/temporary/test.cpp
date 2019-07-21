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

#define maxn 100007
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
ll egcd (ll a,ll b,ll &x,ll &y)
{
    /// ax+by=1 finding x and y where a<b
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd (b%a,a,x1,y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
ll modInv(ll a,ll m)
{
    /// works only when (a,m)=1;
    /// ax=1 (mod m) finding x
    ll x,y;
    if(a<=m)
        egcd(a,m,x,y);
    else
        egcd(m,a,y,x);
    x%=m;
    if(x<0) x+=m;
    /// if x can be very large nand m is prime then use big mod
//    x=bigmod(a,m-2,m)%m;
    return x;
}

ll CRT(const vector< pair<ll, ll> > &vt)
{
    /// pair<ai(residues),pi(primes)>
 	ll M = 1;
 	for(int i = 0; i<vt.size(); i++)
 		M *= vt[i].second;
 	ll ret = 0;
 	for(int i = 0; i<vt.size(); i++)
 	{
 		ll ai = vt[i].first;
 		ll Mi = (M/vt[i].second);
 		ret += ai * Mi * modInv(Mi % vt[i].second, vt[i].second);
 		ret %= M;
 	}
 	return ret;
}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    sf1(tc);
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        sf1(n);
        vector< pair<ll,ll> > vt;
        for(int i=0; i<n; i++)
        {
            ll p,r;
            sf2ll(p,r);
            vt.push_back( {r,p} );
        }
        ll ans = CRT( vt );
        pcase(qq);
        if(ans == -1)
        {
            pf("Impossible\n");
        }
        else
        {
            pf1ll(ans);
        }

    }
    return 0;
}
/*



*/
