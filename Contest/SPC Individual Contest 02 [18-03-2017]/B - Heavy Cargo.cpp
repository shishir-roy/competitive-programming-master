#include<bits/stdc++.h>
using namespace std;
#define DB printf("*****\n")
#define sf scanf
#define pf printf
#define ll long long int
#define maxn 207
#define pii pair<int,int>
#define inf 2147483645
vector<pii>vt[maxn];
int n,r;
struct comp
{
    bool operator ()(pii &a,pii &b)
    {
        return a.second>b.second;
    }
};
int dijkstra(int src,int des)
{
    int dist[maxn];
    for (int i=1; i<=n ; i++ )
    {
        dist[i]=-inf;
    }
    priority_queue<pii,vector<pii>,comp>Q;
    Q.push(pii(src,inf));
    dist[src]=inf;
    while(!Q.empty())
    {
        int u=Q.top().first;
        Q.pop();
        for (int i=0; i<vt[u].size() ; i++ )
        {
            int v=vt[u][i].first;
            int w=vt[u][i].second;
            if(min(dist[u],w)>dist[v])
            {
                dist[v]=max(dist[v],min(dist[u],w) );
                Q.push(pii(v,dist[v]));
            }
        }
    }
   return dist[des];
}
int main()
{
    int tc=1;
    while(sf("%d %d",&n,&r)==2)
    {
        if(n==0 and r==0) return 0;
        for(int i=0; i<=n; i++)
        {
            vt[i].clear();
        }
        map<string,int>mp;
        int mpv=1;
        for(int i=0; i<r; i++)
        {
            string u,v;
            int w;
            cin >> u >> v >> w;
            if(mp.find(u)==mp.end())
            {
                mp[u]=mpv++;
            }
            if(mp.find(v)==mp.end())
            {
                mp[v]=mpv++;
            }
            vt[mp[u]].push_back({mp[v],w});
            vt[mp[v]].push_back({mp[u],w});
        }
        string u,v;
        cin >> u >> v;
        int ans=dijkstra(mp[u],mp[v]);
        pf("Scenario #%d\n",tc++);
        pf("%d tons\n\n",ans);
    }
    return 0;
}
/*
2
3 2
1 2 50
2 3 10

*/
