#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define maxn 100007
#define level 18
vector<int>gr[maxn];

int depth[maxn],par[maxn][level];

void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    par[u][0]=p;
    for(int i=0;i<gr[u].size();i++)
    {
        if(gr[u][i]!=p)
        {
            dfs(gr[u][i],u);
        }
    }
}

void pre(int n)
{
    for(int i=1;i<level;i++)
    {
        for(int node=1;node<=n;node++)
        {
            if(par[node][i-1]!=-1)
            {
                par[node][i] =  par[par[node][i-1]][i-1];
            }
        }
    }
}

int lca(int u,int v)
{
    if(depth[v]<depth[u])
        swap(u,v);

    int diff=depth[v]-depth[u];

    for(int i=0;i<level;i++)
    {
        if((diff>>i)&1)
        {
            v=par[v][i];
        }
    }

    if(v==u) return v;

    for(int i=level-1;i>=0;i--)
    {
        if(par[u][i] != par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }

    return par[u][0];
}

int dist(int u,int v)
{
    int l=lca(u,v);
    int d=depth[u]+depth[v]-2*depth[l];
    return d;
}
int main()
{
    int n,q;
    sf("%d %d",&n,&q);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        sf("%d %d",&u,&v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    depth[0]=0;
    memset(par,-1,sizeof par);
    dfs(1,0);

    pre(n);
    while(q--)
    {
        int a,b,c;
        sf("%d %d %d",&a,&b,&c);
        vector< pair<int,int> > vt;
        vt.push_back({dist(b,a)+dist(a,c),a});
        vt.push_back({dist(a,b)+dist(b,c),b});
        vt.push_back({dist(a,c)+dist(c,b),c});
        int l=lca(a,b);
        vt.push_back({dist(a,l)+dist(b,l)+dist(c,l),l});
        l=lca(b,c);
        vt.push_back({dist(a,l)+dist(b,l)+dist(c,l),l});
        l=lca(a,c);
        vt.push_back({dist(a,l)+dist(b,l)+dist(c,l),l});

        sort(vt.begin(),vt.end());
        cout << vt[0].second << " " << vt[0].first << endl;
    }
    return 0;
}
