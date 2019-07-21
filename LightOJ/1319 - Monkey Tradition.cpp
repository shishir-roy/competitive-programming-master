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

ll CRT(const vector< pair<ll, ll> > &equations)
{
    if (equations.size() == 0) return -1; /// No equations to solve

    ll a1 = equations[0].first;
    ll m1 = equations[0].second;
    a1 %= m1;
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for ( int i = 1; i < equations.size(); i++ )
    {
        ll a2 = equations[i].first;
        ll m2 = equations[i].second;

        ll g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return -1; /// Conflict in equations

        /** Merge the two equations*/
        ll p, q;
        egcd(m1/g, m2/g, p, q);

        ll M = m1 / g * m2;
        ll x = ( a1 * (m2/g) % M *q % M + a2 * (m1/g) % M * p % M ) % M;

        /** Merged equation*/
        a1 = x;
        cout << a1 << " " << M << endl;
        if ( a1 < 0 ) a1 += M;
        m1 = M;
    }
    return a1;
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
