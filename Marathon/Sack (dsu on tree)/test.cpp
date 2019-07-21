#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define maxn 100010
#define X first
#define Y second

vector <int> edge[maxn];
string s;

vector < pair<int,int> > query[maxn];
int sz[maxn], level[maxn], cnt[maxn], ans[maxn], st[maxn], ft[maxn], ver[maxn], timer = 0;
int t[maxn], p[maxn][20];
void getsz(int u, int p)
{
    t[u] = p;
    st[u] = timer;
    ver[timer] = u;
    timer++;
    sz[u] = 1;

    for(auto v : edge[u])
    {
        if(v == p)continue;
        level[v] = level[u]+1;
        getsz(v, u);
        sz[u] += sz[v];
    }
    ft[u] = timer;
}
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
}
void dfs(int u, int p, bool keep)
{
    int mx = -1, big = -1;
    for(auto v : edge[u])
    {
        if(v != p)
        {
            if(sz[v] > mx)
                mx = sz[v], big = v;
        }
    }

    for(auto v : edge[u])
    {

        if(v != p && v != big)
        {
            dfs(v, u, 0);
        }
    }

    if(big != -1)
        dfs(big, u, 1);

    cnt[level[u]]++;

    for(auto v : edge[u])
    {
        if(v != p && v != big)
        {
            for(int t = st[v]; t < ft[v]; t++)
            {
                int vv = ver[t];
                cnt[level[vv]]++;
            }
        }
    }

    for(auto q : query[u])
    {


        //cout<<u<<' '<<level[u]+q.X<<' '<<cnt[level[u]+q.X]<<endl;

        ans[q.Y] = cnt[level[u] + q.X] - 1;
    }

    if(!keep)
    {
        for(int t = st[u]; t < ft[u]; t++)
        {
            int vv = ver[t];
            cnt[level[vv]]--;
        }
    }
}

void lcainit(int n)
{

    memset(p, -1, sizeof(p));



    {for(int i = 0; i <= n; i++)
    {
        p[i][0] = t[i];}}



    for(int j = 1; (1<<j) <= n && j < 19; j++)
        for(int i = 0; i <= n; i++)
    {
        if(p[i][j-1] != -1)
            p[i][j] = p[p[i][j-1]][j-1];

    }

}

int parent(int u, int l, int n)
{
    if(l+1 >= level[u] ) return -1;

    for(int j = 19; j >= 0; j--)
    {
       if(l & (1<<j)) u = p[u][j];
    }

    int p = t[u];

    if(p) return p;
    return -1;
}

 main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin>>n;

    for(int i = 1; i<=n; i++)
    {
        int j;
        cin>>j;
        edge[i].push_back(j);
        edge[j].push_back(i);
    }

    getsz(0, -1);

    lcainit(n);




    cin>>m;

    for(int i = 1; i <= m; i++)
    {
        int u, l;
        cin>>u>>l;


        int p = parent(u, l-1,n );
        if(p == -1) ans[i] =  0 ;
        else
            query[p].push_back({l, i});


    }


    dfs(0, -1, 1);

    for(int i = 1; i<=m ; i++)
    {
        cout<<ans[i]<<' ';
    }





}