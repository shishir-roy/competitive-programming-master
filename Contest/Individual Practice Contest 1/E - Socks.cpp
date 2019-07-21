#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200007
#define sf scanf
#define pf printf
vector<int>gr[maxn];
int col[maxn];
unordered_map<int,int>mp;
int mx=0,flag[maxn];
int tn=0;
void dfs(int u)
{
    flag[u]=1;
    tn++;
    mp[col[u]]++;
    mx=max(mx,mp[col[u]]);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(flag[v]==-1)
        {
            dfs(v);
        }
    }
}
int main()
{

    int n,m,k;
    sf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++)
    {
        sf("%d ", & col[i]);
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        sf("%d %d", &u ,&v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    int ans=0;
    memset(flag,-1,sizeof flag);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==-1)
        {
            mp.clear();
            mx=0;
            tn=0;
            dfs(i);
            ans+=(tn-mx);
        }
    }
    cout << ans << endl;
    return 0;
}
