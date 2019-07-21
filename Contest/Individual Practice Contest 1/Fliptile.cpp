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

int tog(int num,int ps)
{
    return ( num^=(1<<ps) ) ;
}

bool chk(int num,int ps)
{
    return (bool)( num& (1<<ps) );
}
int seti(int num,int ps)
{
    return ( num|=(1<<ps) );
}

int m,n;
int ara[17][17];
vector<int>bits;

void toggle(int r,int c)
{
    tog(bits[r],c);
    if(r-1>=0) tog( bits[r-1], c);
    if(r+1<m) tog(bits[r+1], c);
    if(c-1>=0) tog(r,c-1);
    if(c+1<n) tog(r,c+1);
}
void
int main()
{
    sf2(m,n);
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
         {
              sf1(ara[i][j]);
         }
    }

     return 0;

}
/*



*/
