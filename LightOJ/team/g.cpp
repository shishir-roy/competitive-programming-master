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
#include <iomanip>
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
#define eps                   1e-5
// #define noya vector< vector<int> >(6,vector<int>(6,0))
// #define mat vector<vector<int> >
// #define m 6
using namespace std;
typedef long long int lint;
inline double hudai(lint n)
{
	int f=0;
  for(int i=0;i<5;i++)
  {
  	if((n+5)%10>=5)
  		f=1;
  	else f=0;
  	n/=10;

  }
  if((n+f)%10>=5)
  	n=(n/10)+1;
  else n=n/10;
  return n/100.0;

}
int main()
{
    int test,case_no=1;
    sf1(test);
    while(test--)
    {
    	lint n;
    	lint u=0ll,v=0ll;
    	scanf("%lld",&n);
    	for(lint i=0;i<n;i++)
    	{
    		lint x,y;
    		scanf("%lld %lld",&x,&y);
    		u+=(x*100000000);
    		v+=(y*100000000);
    	}
    	//cout<<"   ghg "<<fround(u)<,endl;
       //double nn=n*1.0;
    	//cout<<u<<" "<<v<<endl;
    	double uu=hudai(u/n);
    	double vv=hudai(v/n);
    	printf("%.2lf %.2lf\n",uu,vv);

    }






	return 0;
}