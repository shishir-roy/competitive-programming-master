/*input

*/
#include<bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define maxn 507
#define ll long long int

vector< pair<int,int> >gr[maxn];
struct cmp
{
	bool operator () (pair<int,int>& a, pair<int,int> & b)
	{
		return a.second > b.second;
	}
};
void dijkstra(int src,int n)
{
	int visit[maxn];
	int dis[maxn];
	memset(visit,0,sizeof visit);
	fill(dis,dis+maxn,INT_MAX);

	priority_queue< pair<int,int> , vector< pair<int,int> > , cmp > pq;
	pq.push(make_pair(src,INT_MIN));
	dis[src]=0;

	while(!pq.empty())
	{
		int u=pq.top().first;
		pq.pop();
		for(int i=0;i<gr[u].size();i++)
		{
			int v=gr[u][i].first;
			int w=gr[u][i].second;
			int t=max(dis[u],w) ;
			if( dis[v]> t)
			{
				dis[v]=t ;
				pq.push(make_pair(v,dis[v]));
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(dis[i]!=INT_MAX)
		{
			pf("%d\n",dis[i]);
		}
		else
		{
			pf("Impossible\n");
		}
	}
}
int main()
{
	int tc;
	sf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,m;
		sf("%d %d",&n,&m);
		for(int i=0;i<maxn;i++) gr[i].clear();

		for(int i=0;i<m;i++)
		{
			int u,v,w;
			sf("%d %d %d",&u,&v,&w);
			gr[u].push_back(make_pair(v,w));
			gr[v].push_back(make_pair(u,w));
		}
		int src;
		sf("%d",&src);
		pf("Case %d:\n",qq);
		dijkstra(src,n);
	}
    return 0;
}