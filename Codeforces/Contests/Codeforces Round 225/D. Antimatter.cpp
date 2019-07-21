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
#define maxn 10007

ll dp[1007][20007];
int n;
ll ara[maxn+7];
ll rec(int ps,int sum)
{
    ll ret = (sum==maxn);
    if(ps>=n)
    {
        return ret;
    }
    if(dp[ps][sum] != -1)
    {
        return dp[ps][sum];
    }
    ret+= rec(ps+1,sum+ara[ps]);
    ret+= rec(ps+1,sum-ara[ps]);
    ret %= mod;
    return dp[ps][sum] = ret;
}
int main()
{
    sf1(n);
    for(int i=0;i<n;i++)
    {
        sf1ll(ara[i]);
    }

    ll ans = 0;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        ans += rec(i+1,maxn+ara[i]);
        ans += rec(i+1,maxn-ara[i]);
        ans %= mod;
//        cout << i << " er jonno " << ans << endl;
    }
    pf1ll(ans);
    return 0;
}
/*



*/
