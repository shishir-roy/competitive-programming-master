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
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 1000007


int main()
{

    ll n,a,b;
    cin >> n >> a >> b;
    ll r = 6LL*n;
    if(a*b>=r)
    {
        pf2ll(a,b);
        return 0;
    }
    ll sq = sqrt(r)+4;
    int mn = inf;
    ll ansa=0,ansb=0;
    for(int x=min(a,b); x<=sq; x++)
    {
        ll y = ceil(double(r)/(1.0*x));
        if(x*y <=mn)
        {
            mn=x*y;
            ansa=x;
            ansb=y;
        }
    }
    if(ansa>=a and ansb>=b)
    {
        pf2ll(ansa,ansb);
    }
    else
    {
        pf2ll(ansb,ansa);
    }
    return 0;
}
/*



*/
