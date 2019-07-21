/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 500000+7
vector<int>gr[maxn];
string s;
int sz[maxn],st[maxn],ft[maxn],ver[maxn],level[maxn],timer=0;
vector< pair<int,int> > query[maxn];
int ans[maxn];
int cnt[maxn][27];
void getsz(int u,int p)
{
    st[u]=timer;
    ver[timer]=u;
    sz[u]=1;
    timer++;
    for(auto v : gr[u])
    {
        if(v!=p)
        {
            level[v]=level[u]+1;
            getsz(v,u);
            sz[u]+=sz[v];
        }
    }
    ft[u]=timer;
}
void dfs(int u,int p,int keep)
{
	int mx=-1,bigchild=-1;
	for(auto v : gr[u])
	{
		if(v!=p and sz[v]>mx)
		{
			mx=sz[v];
			bigchild=v;
		}
	}
	for(int v : gr[u])
	{
		if(v !=p and v!=bigchild)
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
				cnt[level[ver[p]]][s[ver[p]-1]-'a']++;
			}
		}
	}
	cnt[level[u]][s[u-1]-'a']++;
	
	for(auto q : query[u])
	{
		bool f=1;
		int odd=0;
		for(int i=0;i<26;i++)
		{
			if(cnt[q.first][i]&1)odd++;
		}
		if(odd>1)
		{
			f=0;
		}
		ans[q.second]=f;
	}

	if(keep==0)
	{
		for(int p=st[u];p<ft[u];p++)
		{
			cnt[level[ver[p]]][s[ver[p]-1]-'a']--;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=2; i<=n; i++)
    {
        int t;
        cin >> t;
        gr[t].push_back(i);
    }
    cin >> s;
    for(int i=0; i<m; i++)
    {
        int h,v;
        cin >> v >> h;
        query[v].push_back({h,i});
    }
    level[1]=1;
    getsz(1,-1);
    dfs(1,-1,1);
    for(int i=0; i<m; i++)
    {
        if(ans[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}