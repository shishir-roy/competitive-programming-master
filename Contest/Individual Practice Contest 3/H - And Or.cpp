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
bool chk(ll num,int ps)
{
    return (bool) ( num&(1LL<<ps) );
}
ll seti(ll num,int ps)
{
    return num|=(1LL<<ps);
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
        ll a,b;
        sf2ll(a,b);

        ll o=0LL,an=0LL;
        int f=0,st=0;
        for(int i=63; i>=0; i--)
        {
            if(chk(b,i)==1 and st==0)
            {
                st=1;
            }
            if(f)
            {
                o=seti(o,i);
//                cout << "flag " << o << " ** " << an << endl;
                continue;
            }
            if(chk(a,i) != chk(b,i) and st==1)
            {
//                cout << i << " position " << endl;
                o=seti(o,i);
                f=1;
//                cout << o << " " << an << endl;
            }
            else if(chk(a,i) == chk(b,i) and chk(b,i)==1)
            {
//                cout << "fine " << endl;
                o=seti(o,i);
                an=seti(an,i);
            }
        }

        pcase(qq);
        pf2ll(o,an);
    }
    return 0;
}
/*



*/
