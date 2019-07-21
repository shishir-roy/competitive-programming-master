/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>gr[maxn];
int col[maxn],sz[maxn],ver[maxn],st[maxn],cnt[maxn],ft[maxn],timer=0,ans[maxn],koi_bar[maxn];
void getsz(int u,int p)
{
	sz[u]=1;
	ver[timer]=u;
	st[u]=timer;
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
void dfs(int u,int p,int keep)
{
	int mx=-1,bigchild=-1;
	for(int v : gr[u])
	{
		if(v!=p and sz[v])
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
	int mxx=cnt[col[u]];
	for(int v : gr[u])
	{
		if(v!=bigchild)
		{
			for(int p=st[v];p<ft[v];p++)
			{
				cnt[col[ver[p]]]++;
				mxx=max(mxx,cnt[col[ver[p]]]);
				koi_bar[cnt[col[ver[p]]]]++;
			}
		}
	}
	ans[u]=koi_bar[mxx]*mxx;
	if(keep==0)
	{
		for(int p=st[u];p<ft[u];p++)
		{
			cnt[col[ver[p]]]--;
			koi_bar[cnt[col[ver[p]]]]--;
		}
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
    dfs(1,-1,1);
    for(int i=1;i<=n;i++)
    	cout << ans[i] << " ";
    return 0;
}