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
#define pf1(a)                printf("%d",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 207
vector<int>gr[maxn];
bool mat[maxn][maxn];

bool cmp(pii a, pii b)
{
     if(a.fs != b.fs)
     {
          return a.sc < b.sc;
     }
     return a.fs > b.fs;
}
int main()
{
    int tc;
    sf1(tc);
    for(int qq=1;qq<=tc;qq++)
    {
         for(int i=0;i<maxn;i++)
         {
              gr[i].clear();
         }
         int n,m;
         sf2(n,m);

         int col[maxn];
         for(int i=0;i<n;i++)
         {
              sf1(col[i]);
         }
         memset(mat,0,sizeof mat);
         for(int i=0;i<m;i++)
         {
              int x,y;
              sf2(x,y);
              if(mat[x][y]==0)
              {
                   mat[x][y] = 1;
                   mat[y][x] = 1;
                   gr[x].push_back(y);
                   gr[y].push_back(x);
              }
         }


         /// degree set kortechi
         vector< pii > vt;
         for(int i=0;i<n;i++)
         {
              vt.push_back(make_pair(gr[i].size(),i) );
         }
         sort(vt.begin(),vt.end() ,cmp);

         int cnt=0;
         vector<int>ans;
         for(int i=0;i<vt.size();i++)
         {
              int u = vt[i].sc;
              for(int i=0;i<gr[u].size();i++)
              {
                    int v = gr[u][i];
                   if(mat[u][v] and col[u]!=col[v])
                   {
                        mat[u][v]=0;
                        mat[v][u]=0;
                        cnt++;
                        ans.push_back(u);
                   }
              }
         }

         sort(ans.begin(), ans.end() );
         pf1(cnt);
         for(int i=0;i<ans.size();i++)
         {
              pf(" %d",ans[i]);
         }
         pf("\n");
    }
    return 0;

}
/*



*/
