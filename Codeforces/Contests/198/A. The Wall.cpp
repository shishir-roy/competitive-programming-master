#include<bits/stdc++.h>
#define pii                   pair<int,int>
#define tii                   pair<int,pair<int,int> >
#define fs                    first
#define sc                    second
#define DB                    cout<<"*****"<<endl;

#define mod                   1000000007
#define inf                   1000000007
#define pi                    acos(-1.0)

#define sf                    scanf
#define pf                    printf
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
#define pcase(x)              printf("Case %d: ",x)

#define ll                    long long int
#define maxn                  100007
using namespace std;


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    ll t=x*y/__gcd(x,y);
    cout << (b/t)-(a-1)/t << endl;
    return 0;
}
/*

*/






