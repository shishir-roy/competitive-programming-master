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
int m,n;
int rad[507][507], ura[507][507];
int dp[507][507];

int rec(int r,int c)
{
    if(r<1 || c<1)
    {
        return 0;
    }
    int &ret=dp[r][c];
    if(ret != -1)
    {
        return ret;
    }
    ret=0;
    ret = max( ura[r][c]+rec(r-1,c), rad[r][c]+rec(r,c-1) );
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
        sf2(m,n);

        memset(rad,0,sizeof rad);
        memset(ura,0,sizeof ura);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int x;
                sf1(x);
                ura[i][j] = ura[i][j-1] + x;
            }
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int x;
                sf1(x);
                rad[i][j] = rad[i-1][j] + x;
            }
        }

        memset(dp,-1,sizeof dp);
        int t = rec(m,n);
        pcase(qq);
        pf1(t);
    }

    return 0;
}
/*



*/
