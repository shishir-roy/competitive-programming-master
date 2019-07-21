#include<bits/stdc++.h>

using namespace std;
#define int long long
#define maxn 500010
#define X first
#define Y second
vector <int> gr[maxn];
string s;
vector < pair<int,int> > query[maxn];
int sz[maxn], level[maxn], cnt[maxn][27], ans[maxn], st[maxn], ft[maxn], ver[maxn], timer = 0;
void getsz(int u, int p)
{
    st[u] = timer;
    ver[timer] = u;
    timer++;
    sz[u] = 1;

    for(auto v : gr[u])
    {
        if(v == p)continue;
        level[v] = level[u]+1;
        getsz(v, u);
        sz[u] += sz[v];
    }
    ft[u] = timer;
}
void dfs(int u, int p, bool keep)
{
    int mx = -1, bigchild = -1;
    for(auto v : gr[u])
    {
        if(v != p)
        {
            if(sz[v] > mx)
                mx = sz[v], bigchild = v;
        }
    }
    for(auto v : gr[u])
    {
        if(v != p && v != bigchild)
        {
            dfs(v, u, 0);
        }
    }
    if(bigchild != -1)
        dfs(bigchild, u, 1);
    cnt[level[u]][s[u-1] - 'a']++;
    for(auto v : gr[u])
    {
        if(v != p && v != bigchild)
        {
            for(int t = st[v]; t < ft[v]; t++)
            {
                int vv = ver[t];
                cnt[level[vv]][s[vv-1] - 'a']++;
            }
        }
    }
    for(auto q : query[u])
    {
        bool f = true;
        int bejor = 0;
        for(int i = 0; i < 26; i++)
        {
            int temp = cnt[q.first][i];
            if(temp&1) bejor++;
        }
        if(bejor > 1) f = false;
        ans[q.second] = f;
    }
    if(!keep)
    {
        for(int t = st[u]; t < ft[u]; t++)
        {
            int vv = ver[t];
            cnt[level[vv]][s[vv-1] - 'a']--;
        }
    }
}

main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i = 2; i<=n; i++)
    {
        int j;
        cin>>j;
        //gr[i].push_back(j);
        gr[j].push_back(i);
    }

    cin>>s;

    for(int i = 1; i <= m; i++)
    {
        int u, l;
        cin>>u>>l;
        query[u].push_back({l, i});

    }
    level[1]=1;
    getsz(1, -1);
    dfs(1, -1, 1);
    for(int i = 1; i<=m ; i++)
    {
        if(ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
