#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define DB                    cout<<" **** "<<endl;
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

int main()
{
    int n,k,m,a;
    sf2(n,k);
    sf2(m,a);
    int cnt[maxn];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<m;i++)
    {
         int t;
         sf1(t);
         cnt[t]++;
    }

    int ans[maxn];
    memset(ans,0,sizeof ans);
    int mx = INT_MIN;
    for(int i=1;i<=n;i++)
    {
         mx = max(mx,ara[i]);
    }
    int nos_case = m - a, temp = 0 ;
    for(int i=1;i<=n;i++)
    {
         if(ara[i]>)
    }
    return 0;

}
/*



*/
