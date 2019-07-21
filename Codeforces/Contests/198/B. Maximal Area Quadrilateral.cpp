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

struct PT{
    int x,y;

    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (double c)    const { return PT(x*c, y*c); }
    PT operator / (double c)    const { return PT(x/c,y/c); }
};

int cross(PT &p, PT &q) { return p.x*q.y-p.y*q.x; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    PT points[n+7];
    for(int i=0;i<n;i++)
    {
        cin >> points[i].x >> points[i].y ;
    }

    vector < PT > dia;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dia.push_back( PT(points[i]+points[j]) );
        }
    }

    for(int i=0;i<dia.size();i++)
    {
        for(int i)
    }
    return 0;
}
/*

*/






