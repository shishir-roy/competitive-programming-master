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
#define pf1ll(a)              printf("%lld",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 1000007

bool ok(ll t)
{
    int d=0;
    ll temp = t;
    while(t)
    {
        t/=10;
        d++;
    }
    t=temp*temp;
    ll y = t;
    ll x=0,p=1;
    while(d--)
    {
        int c=t%10;
        t/=10;
        x+=(c*p);
        p*=10;
    }
//    cout << temp << " " << y << " " << x << " " << t << endl;
    return t+x==temp;
}
int main()
{
    ll p,q;
    sf2ll(p,q);
    int f=0;
    for(ll i=p;i<=q;i++)
    {
        if(ok(i))
        {
            if(!f)
            {
                pf1ll(i);
            }
            else
            {
                pf(" %lld",i);
            }
            f=1;
        }
    }
    if(!f)
    {
        pf("INVALID RANGE");
    }
    return 0;
}
/*



*/
