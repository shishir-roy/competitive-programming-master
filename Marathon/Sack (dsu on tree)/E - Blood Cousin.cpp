/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define level 20
vector<int>gr[maxn];
vector< pair<int,int> >query[maxn];
int st[maxn],ft[maxn],sz[maxn],depth[maxn],ver[maxn],par[maxn][level+7],cnt[maxn],ans[maxn];
int n,timer=0;
void getsz(int u,int p)
{
	sz[u]=1;
	st[u]=timer;
	ver[timer]=u;
	par[u][0]=p;
	timer++;
	for(int v: gr[u])
	{
		if(v!=p)
		{
			depth[v]=depth[u]+1;
			getsz(v,u);
			sz[u]+=sz[v];
		}
	}
	ft[u]=timer;
}
void preprocess()
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
int jump(int u,int k)
{
	for(int j=level-1;j>=0;j--)
	{
		if((k>>j)&1)
		{
			u=par[u][j];
		}
	}
	int t=par[u][0];
	if(t) return t;
	return -1;
}
void dfs(int u,int p,int keep)
{
	int mx=-1,bigchild=-1;
	for(int v: gr[u])
	{
		if(v!=p and sz[v]>mx)
		{
			mx=sz[v];
			bigchild=v;
		}
	}
	for(int v:gr[u])
	{
		if(v!=p and v!=bigchild)
		{
			dfs(v,u,0);
		}
	}
	if(bigchild!=-1)
	{
		dfs(bigchild,u,1);
	}
	for(int v : gr[u])
	{
		if(v!=p and v!=bigchild)
		{
			for(int p=st[v];p<ft[v];p++)
			{
				cnt[depth[ver[p]]]++;
			}
		}
	}
	cnt[depth[u]]++;
	for(auto q:query[u])
	{
		ans[q.second]=cnt[q.first+depth[u]]-1;
	}
	if(keep==0)
	{
		for(int p=st[u];p<ft[u];p++)
		{
			cnt[depth[ver[p]]]--;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	int p;
    	cin >> p;
    	gr[p].push_back(i);
    	gr[i].push_back(p);
    }
    memset(par,-1,sizeof par);
    getsz(0,-1);
    preprocess();
    /*cout << jump(2,0) << endl;*/
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
    	int v,h;
    	cin >> v >>h;
    	int t=jump(v,h-1);
    	if(t==-1)
    		ans[i]=0;
    	else
    	{
    		query[t].push_back({h,i});
    	}
    }
   /* cout << "####" << endl;*/
    dfs(0,-1,1);
    for(int i=0;i<q;i++)
    	cout << ans[i] << " ";
    return 0;
}