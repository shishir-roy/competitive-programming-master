/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>gr[maxn];
int sz[maxn],st[maxn],ft[maxn],ver[maxn],timer=0,col[maxn];
void getsz(int u,int p)
{
	sz[u]=1;
	st[u]=timer;
	ver[timer]=u;
	timer++;
	for(int v : gr[u])
	{
		if(v!=p)
		{
			getsz(v,u);
			sz[u]+=sz[v];
		}
	}
	ft[u]=timer;
}
int cnt[maxn],dom[maxn];
ll ans[maxn];
void dfs(int u,int p,int keep)
{
	int mx=-1,bigchild=-1;
	for(int v : gr[u])
	{
		if(v!=p and sz[v]>mx)
		{
			mx=sz[v];
			bigchild=v;
		}
	}
	for(int v : gr[u])
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
	cnt[col[u]]++;
	int mxc=cnt[col[u]];
	for(int v : gr[u])
	{
		if(v!=p and v!=bigchild)
		{
			for(int p=st[v];p<ft[v];p++)
			{
				cnt[col[ver[p]]]++;
				mxc=max(mxc,cnt[col[ver[p]]]);
			}
		}
	}
	if(bigchild!=-1 and dom[bigchild]==mxc)
	{
		ll t=ans[bigchild];
		unordered_set<int>sat;
		if(mxc==cnt[col[u]])
		{
			sat.insert(col[u]);
		}
		for(int v : gr[u])
		{
			if(v!=p and v!=bigchild)
			{
				for(int p=st[v];p<ft[v];p++)
				{
					if(mxc==cnt[col[ver[p]]])
					{
						sat.insert(col[ver[p]]);
					}
				}
			}
		}
		for(int it : sat)
		{
			t+=it;
		}
		ans[u]=t;
		dom[u]=mxc;
	}
	else if(bigchild!=-1 and dom[bigchild]>mxc)
	{
		ans[u]=ans[bigchild];
		dom[u]=dom[bigchild];
	}
	else
	{
		ll t=0;
		unordered_set<int>sat;
		if(mxc==cnt[col[u]])
		{
			sat.insert(col[u]);
		}
		for(int v : gr[u])
		{
			if(v!=p and v!=bigchild)
			{
				for(int p=st[v];p<ft[v];p++)
				{
					if(mxc==cnt[col[ver[p]]])
					{
						sat.insert(col[ver[p]]);
					}
				}
			}
		}
		for(int it : sat)
		{
			t+=it;
		}
		ans[u]=t;
		dom[u]=mxc;
	}
	if(keep==0)
	{
		for(int p=st[u];p<ft[u];p++)
		{
			cnt[col[ver[p]]]--;
		}
		dom[u]=0;
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	cin >> col[i];
    }
    for(int i=0;i<n-1;i++)
    {
    	int u,v;
    	cin >> u >> v;
    	gr[u].push_back(v);
    	gr[v].push_back(u);
    }
    getsz(1,-1);
    /*cout << " ok " << endl;*/
    dfs(1,-1,1);
    for(int i=1;i<=n;i++)
    	cout << ans[i] << " ";
    return 0;
}