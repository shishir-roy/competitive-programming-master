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
#define pcase(x)              printf("Case %d:\n",x)
#define hi                    cout<<"hi"<<endl;
#define mod                   1000000007
#define inf                   1000000107
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

int main()
{

   // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  //#endif

   int test,case_no=1;
  sf1(test);
  while(test--)
  {
  	int n,e;
  	sf2(n,e);
  	vector<pii>vt[n+5];
  	int mark[n+5];
  	for (int i = 0;i<=n;i++) mark[i] = -inf;
  	//mem(mark,-1);
  	for(int i=0;i<e;i++)
  	{
  		int u,v,w;
  		sf3(u,v,w);
  		vt[u].push_back(jora(v,w));
  		vt[v].push_back(jora(u,w));
  	}
  	mark[1]=inf;

  	priority_queue< pii, vector<pii> >pq;
  	pq.push(jora(0,1));
  	while(pq.size())
  	{
  		int u=pq.top().sc;
  		pq.pop();
  		for(int i=0;i<vt[u].size();i++)
  		{
  			int v=vt[u][i].fs;
  			int w=vt[u][i].sc;
  			if(mark[v]<min(w,mark[u]))
  			{
  				mark[v]=min(w,mark[u]);
  				pq.push(jora(mark[v],v));
  			}

  		}
  	}
  	vector<int>vv;
  	vector<int>::iterator it;
  pcase(case_no++);
  	for(int i=2;i<=n;i++)
  	{
  		vv.push_back(mark[i]);
  		//cout<<i<<" "<<mark[i]<<endl;
  	}
  	sort(vv.begin(),vv.end());
  	int q;
  	sf1(q);
  	while(q--)
  	{
  		int c;
  		sf1(c);
  		it=lower_bound(vv.begin(),vv.end(),c);
  		int x=(it-vv.begin());
  		//cout<<"meaw "<<x<<endl;
  		printf("%d\n",vv.size()-x);
  	}
  }






	return 0;
}
/*inpt
2
4 3
2 3 2
1 2 3
4 3 4
3
2
3
4
4 4
1 2 3
2 4 2
3 4 1
1 3 4
3
-12
-15
0
*/
