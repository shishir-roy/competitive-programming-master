#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
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
 int h,n,k;

 int dp[107][107][5];

 int rec(int ps,int cnt,int prev)
 {
      if(ps>=n)
      {
           if(cnt==k)
               return 1;
           return 0;
      }
      if(cnt>k)
          return 0;
      int &ret = dp[ps][cnt][prev];
      if(ret != -1) return ret;
      ret=rec(ps+1,cnt,0);
      if(prev==1)
      {
           ret+=rec(ps+1,cnt+1,1);
      }
      else
      {
           ret+=rec(ps+1,cnt,1);
      }
      return ret;
 }
int main()
{
    int tc;
    sf1(tc);
    for(int qq=1;qq<=tc;qq++)
    {
         sf3(h,n,k);
         memset(dp,-1,sizeof dp);
         int t = rec(0,0,0);
         pf("%d %d\n",qq,t);
    }
    return 0;

}
/*



*/
