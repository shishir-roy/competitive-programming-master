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
int a[15][15];
inline bool hudai(int r1,int r2,int c1,int c2)
{
	if((r2-r1+1)*(c2-c1+1)!=10)
		return false;
	int mark[15]={0};
	for(int i=r1;i<=r2;i++)
		for(int j=c1;j<=c2;j++)
			mark[a[i][j]]++;
		for(int i=1;i<=10;i++)
			if(mark[i]!=1)
				return false;
			return true;
}
int main()
{


   int test,case_no=1;
   sf1(test);
   while(test--)
   {
      int n;
      sf1(n);
      for(int i=0;i<n;i++)
      	for(int j=0;j<n;j++)
      		sf1(a[i][j]);
      	int cnt=0;
      	for(int i=0;i<n;i++)
      		for(int j=i;j<n;j++)
      			for(int x=0;x<n;x++)
      				for(int y=x;y<n;y++)
      				{
      				    if(hudai(i,j,x,y))
      				    	cnt++;
      				}
   pcase(case_no++);
   pf1(cnt);


   }






	return 0;
}
