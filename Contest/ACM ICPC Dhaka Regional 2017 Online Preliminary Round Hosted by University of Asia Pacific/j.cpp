
/*

author : Avi Mallick
      CSE'15 SUST

*/
#include<bits/stdc++.h>
#define pii                   pair<int,int>
#define tii                   pair<int,pair<int,int> >
#define mkp                   make_pair
#define fs                    first
#define sc                    second
#define pb                    push_back
#define ppb                   pop_back()
#define pcase(x)              printf("Case %d: ",x)
#define hi                    cout<<"hi"<<endl;
#define mod                   1000000007
#define inf                   1000000007
#define pi                    acos(-1.0)
#define mem(arr,x)            memset((arr), (x), sizeof((arr)));
#define FOR(i,x)              for(int i=0;i<(x); i++)
#define FOR1(i,x)             for(int i = 1; i<=(x) ; i++)
#define jora(a,b)             make_pair(a,b)
#define tora(a,b,c)           jora(a,jora(b,c))
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
#define N 100005
#define level 26
// #define noya vector< vector<int> >(6,vector<int>(6,0))
// #define mat vector<vector<int> >
// #define m 6
using namespace std;
typedef long long int lint;
typedef double dbl;
inline double dis(double a,double b,double c,double d)
{
    double x=(a-c);
    double y=(b-d);
    return x*x+y*y;

}
int main()
{



   int test,case_no=1;
  // sf1(test);
  cin>>test;
   while(test--)
   {
     double bx,by,ax,t,w;
     cin>>bx>>by>>ax>>w>>t;
     double m=ax;
     double f;
     double l=dis(bx,by,ax,0.0);
       if(ax<0.0)
        ax*=(-1.0);
     double r=dis(bx,by,0.0,0.0);
     double an=(r+ax*ax-l)/(2.0*sqrt(r)*ax);
     if(m<0.0)
        f=-1.0;
     else f=1.0;
     an=acos(an);
     an+=(t*w*f);
     double a=1.0;
     double b=-2.0*sqrt(r)*cos(an);
     double c=(r-l);
     double x=(-b+sqrt(b*b-4*a*c))/2.0;
     if(m<0.0)
        x*=(-1.0);
    cout<<"Case "<<case_no++<<": "<<setprecision(6)<<fixed<<x<<endl;


   }






	return 0;
}
