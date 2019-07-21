#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<ll,ll>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
#define mod                   1000000007
#define inf                   ll_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    prllf
#define pcase(x)              prllf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                prllf("%d\n",a);
#define pf2(a,b)              prllf("%d %d\n",a,b)
#define pf3(a,b,c)            prllf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              prllf("%lld\n",a);
#define pf2ll(a,b)            prllf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          prllf("%lld %lld %lld\n",a,b,c)

#define maxn 500007
    ll pre[maxn],suff[maxn];
    ll ara[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;

    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin >> ara[i];
        sum+=ara[i];
    }
    if(sum%3)
    {
        cout << 0 << endl;
        return 0;
    }
    sum/=3;

    memset(pre,0,sizeof pre);
    memset(suff,0,sizeof suff);
    ll t=0;
    for(ll i=0;i<n;i++)
    {
        t+=ara[i];
        if(t==sum)
        {
            pre[i] = 1;
        }
    }

    t=0;
    for(ll i=n-1;i>=0;i--)
    {
        t+=ara[i];
        if(t==sum )
        {
            suff[i] =1;
        }
    }

    for(ll i=n-1;i>=0;i--)
    {
        suff[i]+=suff[i+1];
    }

    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(pre[i]==1)
        {
            cnt+=suff[i+2];
        }
    }
    cout << cnt << endl;
    return 0;
}
/*



*/
