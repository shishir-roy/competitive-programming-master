/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 10000+7
#define level 20
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
int jump(int u,int k)
{
    for(int i=0;i<level;i++)
    {
        if((k>>i)&1)
        {
            u=par[u][i];
        }
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        for(int i=0;i<=n;i++)
            gr[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v,c;
            cin >> u >> v >> c;
            gr[u].push_back({v,c});
            gr[v].push_back({u,c});
        }
        memset(par,-1,sizeof par);
        depth[0]=0;
        dfs(1,0);
        preprocess(n);
        string str;
        while(cin >> str)
        {
            if(str=="DIST")
            {
                int u,v;
                cin >> u >> v;
                int t=lca(u,v);
                cout << dis[u]+dis[v]-2*dis[t] << endl;
            }
            else if(str=="KTH")
            {
                int u,v,k;
                cin >> u >> v >> k;
                int t=lca(u,v);
                int du=depth[u]-depth[t]+1;
                if(k<=du)
                {
                    cout << jump(u,k-1) << endl;
                }
                else
                {
                    int dv=depth[v]-depth[t];
                    k-=du;
                    int aa=dv-k;
                    cout << jump(v,aa) << endl;
                }
            }
            else if(str=="DONE")
            {
                break;
            }
        }
    }
    return 0;
}