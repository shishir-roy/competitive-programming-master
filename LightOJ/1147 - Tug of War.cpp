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

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    sf1(tc);
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        sf1(n);
        int sum = 0;
        int ara[n+7];
        for(int i=0;i<n;i++)
        {
            sf1(ara[i]);
            sum += ara[i];
        }

        int hf = (sum+1)/2;
        int a = n/2;
        int b = (n+1)/2;

        bitset<55>dp[hf+7];
        dp[0]= 1 ;
        for(int i=0;i<n;i++)
        {
            for(int j=hf;j>=ara[i];j--)
            {
                dp[j] = ( dp[j] | ( dp[ j - ara[i] ]<<1LL ) );
            }
        }

        pcase(qq);
        for(int j=hf;j>=0;j--)
        {
            if( dp[j][a]==1 ||  dp[j][b]==1)
            {
                pf("%d %d\n",min(j,sum-j), max(j,sum-j) );
                break;
            }
        }
    }
    return 0;
}
/*



*/
