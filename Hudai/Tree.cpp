/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 60000+7
#define level 15
vector< pair<int,ll> > gr[maxn];
int depth[maxn],par[maxn][level+7];
ll dis[maxn];
ll temp[maxn];
void dfs1(int u,int p)
{
	for(auto v:gr[u])
	{
		if(v.first!=p)
		{
			temp[v.first]=temp[u]+v.second;
			dfs1(v.first,u);
		}
	}
}
void dfs(int u,int p)
{
	depth[u]=depth[p]+1;
	par[u][0]=p;
	for(auto v:gr[u])
	{
		if(v.first!=p)
		{
			dis[v.first]=dis[u]+v.second;
			dfs(v.first,u);
		}
	}
}
void preprocess(int n)
{
	for(int j=1;j<level;j++)
	{
		for(int node=1;node<=n;node++)
		{
			if(par[node][j-1]!=-1)
			{
				par[node][j]=par[par[node][j-1]][j-1];
			}
		}
	}
}
int lca(int u,int v)
{
	if(depth[u]<depth[v])
	{
		swap(u,v);
	}
	int diff=depth[u]-depth[v];
	for(int i=0;i<level;i++)
	{
		if((diff>>i)&1)
		{
			u=par[u][i];
		}
	}
	if(u==v)
		return u;
	for(int i=level-1;i>=0;i--)
	{
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

int main()
{
	/*freopen("I.IN","r",stdin);*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
    	gr[u].push_back({v,w});
    	gr[v].push_back({u,w});
    }
    dfs(1,-1);
    /*cout << "ok" << endl;*/
    preprocess(n);
    int a=-1,mx=-1;
    for(int i=1;i<=n;i++)
    {
    	if(dis[i]>mx)
    	{
    		mx=dis[i];
    		a=i;
    	}
    }

    cout << "a " << a << " " << dis[a] << endl;
    dfs1(a,-1);
    int b=-1;
    mx=-1;
    for(int i=1;i<=n;i++)
    {
    	if(temp[i]>mx)
    	{
    		mx=temp[i];
    		b=i;
    	}
    }
    cout << "b " << b << " " << dis[b] << endl;
    ll ans[maxn];
    for(int i=1;i<=n;i++)
    {
    	ans[i]=max( dis[a]+dis[i]-2*dis[lca(a,i)], dis[b]+dis[i]-2*dis[lca(b,i)] );
    }
    for(int i=1;i<=n;i++)
    	cout << ans[i] << endl;
    return 0;
}