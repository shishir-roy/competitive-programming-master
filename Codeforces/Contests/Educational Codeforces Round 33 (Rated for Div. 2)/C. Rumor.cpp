#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>gr[maxn];
ll gold[maxn];
ll mn;
int flag[maxn];
void dfs(int u)
{
    flag[u]=1;
    mn=min(mn,gold[u]);
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> gold[i];
    }
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    ll ans=0;
    memset(flag,-1,sizeof flag);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==-1)
        {
            mn=INT_MAX;
            dfs(i);
            ans+=mn;
        }
    }
    cout << ans << endl;
    return 0;

}
