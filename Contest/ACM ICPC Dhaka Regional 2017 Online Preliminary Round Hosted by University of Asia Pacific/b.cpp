
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
lint fac[200005];
lint inv[200005];
inline lint bigmod(lint a,lint b,lint m)
{
    /// a^b%m
    lint ans=1;
    while(b>0)
    {
        if(b&1ll)
            ans=(a*ans)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
}

inline void pre()
{
    fac[0]=1;
    for(lint i=1;i<=200003;i++)
        fac[i]=(fac[i-1]*i)%mod;
        for(lint i=0;i<=200003;i++)
            inv[i]=bigmod(fac[i],mod-2,mod);


  return ;
}
inline lint ncr(int n,int k)
{
    if(n==0 || k==0)
        return 1ll;
    return (((fac[n+k-1]*inv[k])%mod)*inv[n-1])%mod;

}
int main()
{



   int test,case_no=1;
   sf1(test);
   pre();
   while(test--)
   {
    int n,x;
    sf2(n,x);
    int mark[n+4];
    mem(mark,-1);
    for(int i=0;i<x;i++)
    {

        int x,y;
        sf2(x,y);
        mark[x]=y;
    }
    lint ans=1;
    int last=1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {

        if(mark[i]!=-1)
        {
           // cout<<mark[i]-last+1<<" "<<cnt<<endl;
            ans=(ans*ncr(mark[i]-last+1,cnt))%mod;
            cnt=0;
            last=mark[i];


        }
        else cnt++;

    }
    ans=(ans*ncr(n-last+1,cnt))%mod;
    pcase(case_no++);
    printf("%lld\n",ans);


   }





	return 0;
}
