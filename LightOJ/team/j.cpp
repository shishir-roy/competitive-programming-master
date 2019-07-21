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
int main()
{
  int n;
   	char c;
   while(scanf("%d%c",&n,&c))
   {
   	if(n==0)
   		break;

   	
   	vector<int>vt[105];
   	char a[105];
   	for(int i=0;i<n;i++)
   	{
       scanf("%s",a);
       for(int j=0;j<n;j++)
       	if(a[j]=='1')
       		vt[i].push_back(j);
       //	cout<<vt[i].size();
       	//printf("%s\n",a);
       	// for(int u : vt[i])
       	// 	cout<<u<<" ";
       	// cout<<endl;
   	}
   	int cnt=0;
   	int mark[105][105];
    mem(mark,-1);
 for(int i=0;i<n;i++)
 {
 	queue<int>q;
 	q.push(i);
 	mark[i][i]=0;
 	while(q.size())
 	{
      int u=q.front();
      q.pop();
      for(int bal=0;bal<vt[u].size();bal++)

      {
      	int v=vt[bal];
      	if(mark[i][v]!=-1)
      		continue;
      	mark[i][v]=mark[i][u]+1;
      	q.push(v);
      }
 	}
 }
// for(int i=0;i<n;i++)
// {
// 	for(int j=0;j<n;j++)
// 		cout<<mark[i][j]<<" ";
// 	cout<<endl;

// }
   for(int node=0;node<n;node++)
   {
      int f=0;
      for(int s=0;s<n && f==0;s++)
      {
      	if(s==node)
      		continue;
       queue<int>q;
 	
 	int vis[105];
 	mem(vis,-1);
 	q.push(s);
 	vis[s]=0;
 	while(q.size() && f==0)
 	{
      int u=q.front();
      q.pop();
      for(int v : vt[u])
      {
      	if(vis[v]!=-1 || v == node)
      		continue;
      	vis[v]=vis[u]+1;
      	q.push(v);
      	if(vis[v]>mark[s][v])
      	{
      		//cout<<node<<" "<<s<<" "<<v<<endl;
      		f=1;
      		cnt++;
      		break;
      	}
      }
 	}
 	for(int i=0;i<n && f==0;i++)
 		if(vis[i]==-1 && i!=node && mark[s][i]!=-1)
 		{
           //cout<<node<<" gg "<<s<<" "<<i<<" "<<vis[i]<<" "<<mark[s][i]<<endl;
 			cnt++;
 			f=1;
 			break;
         }
        
         	
 	   }




   }

   printf("%d\n",cnt);

   }



	return 0;
}