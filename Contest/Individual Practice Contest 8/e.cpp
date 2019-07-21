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
    while(b>0LL)
    {
        if(b&1LL)
            ans=(a*ans)%m;
        b>>=1LL;
        a=(a*a)%m;
    }
    return ans;
}

vector<int>vt;
void div(int b)
{
    int sq=sqrt(b)+5;
    for(int i=1;i<sq;i++)
    {
        if(b%i==0)
        {
            vt.push_back(i);
            vt.push_back(b/i);
        }
    }
    sort(vt.begin(),vt.end());
}
int main()
{
    ios_base::sync_with_stdio(0);
    ll a,b,p,x;
    cin >> a >> b >> p >> x ;
    div(b);
    int cnt=0;
    for(int i=0;i<vt.size()&&vt[i]<=x;i++)
    {
        ll x = bigmod(a,vt[i],p);
        ll y = (x*vt[i])%p;
        if(y==b)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
/*



*/
