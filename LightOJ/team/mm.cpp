/*input
6
1 2 3 4 5 6
6 5 4 3 2 1
*/
/*

author : Avi Mallick
      CSE'15 SUST

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
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
// #define n                      10000007
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

// #define noya vector< vector<int> >(6,vector<int>(6,0))
// #define mat vector<vector<int> >
// #define m 6
using namespace std;
typedef long long int lint;
int sum[205][205];
int a[205][205];
inline void pre(int n,int m)
{
	for(int i=1;i<=m;i++)
		sum[1][i]=a[1][i];
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j];
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				sum[i][j]+=sum[i][j-1];
			return ;

}
inline int hudai(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]+sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1];
}
int main()
{
    int n,m,r,c;
    while(scanf("%d",&n))
    {
    	if(n==0)
    		break;
    	scanf("%d %d %d",&m,&r,&c);
   mem(sum,0);
   for(int i=1;i<=n;i++)
   	for(int j=1;j<=m;j++)
   	scanf("%d",&a[i][j]);
   pre(n,m);
   int x1,x2;int y1,y2;
   int ans=-inf;
   for(int k=1;k<=min(n,m);k++)

   {
   	if(i+r-k)
   	for(int i=1;i<=n-r+1;i++)
   	  for(int j=1;j<=m-c+1;j++)
   	  {
   	  	int s=hudai(i,j,i+r-1,j+c-1);
   	  	
   	  }
   	}
   	  printf("%d %d %d %d\n",x,y,x+r-1,y+c-1);

    }



	return 0;
}