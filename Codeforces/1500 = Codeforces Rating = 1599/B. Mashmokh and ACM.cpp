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

#define maxn 2007
int n,k;
vector<int>vt[maxn];
ll dp[maxn][maxn];

ll rec(int cnt,int prev)
{
    if(cnt==k)
    {
        return 1;
    }
    ll &ret = dp[cnt][prev];
    if(ret != -1) return ret;
    ret =0 ;
    for(int i=0; i<vt[prev].size() && vt[prev][i]<=n; i++)
    {
        ret+=rec(cnt+1,vt[prev][i]);
        ret%=mod;
    }

    return ret;
}
int main()
{
    for(int i=1; i<maxn; i++)
    {
        for(int j=i; j<maxn; j++)
        {
            if(j%i==0)
            {
                vt[i].push_back(j);
            }
        }
    }


    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    cin >> n >> k;
    memset(dp,-1,sizeof dp);
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans+=rec(1,i);
        ans%=mod;
    }

    cout << ans << endl;
    return 0;
}
/*



*/
