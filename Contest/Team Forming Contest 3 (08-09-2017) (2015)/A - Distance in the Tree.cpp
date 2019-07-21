/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define level 20
#define maxn 50000+7
vector< pair<int,int> >gr[maxn];
int depth[maxn],dis[maxn],par[maxn][level+7];
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
        for(int node=0;node<n;node++)
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
    dfs(0,-1);
    preprocess(n);
    int m;
    cin >> m;
    while(m--)
    {
    	int u,v;
    	cin >> u >> v;
        int t=lca(u,v);
        /*cout << t << endl;*/
    	cout << dis[u]+dis[v]-dis[t]*2 << endl;
    }
    return 0;
}