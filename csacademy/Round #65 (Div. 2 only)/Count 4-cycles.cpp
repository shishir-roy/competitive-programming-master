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
#define maxn 100000
int main()
{
    int n;
    sf1(n);
    map< pair<int,int> , bool > mp;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        mp[ {u,v}] = 1;
    }
    int cnt =0 ;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        if( mp.find({u,v})!=mp.end() || mp.find({v,u})!=mp.end() )
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
/*



*/
