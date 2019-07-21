#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 10007
int n,m,root,ti;
vector<int>gh[maxn];
set<int>st;
int d[maxn],parent[maxn],low[maxn];
bool visit[maxn];
void art(int u)
{
    d[u]=ti;
    low[u]=ti;
    ti++;
    visit[u]=1;
    int child=0;
    for(int i=0 ;i<gh[u].size() ; i++ )
    {
        int v=gh[u][i];
        if(v==parent[u]) continue;
        if(visit[v])
        {
            low[u]=min(low[u],d[v]);
        }
        else
        {
            parent[v]=u;
//            cout << u << " --> " << v << endl;
            art(v);
//            cout << "after call " << u << endl;
            child++;
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v] && u!=root)
            {
                st.insert(u);
            }
        }
    }
    if(child>1 && u==root)
    {
        st.insert(u);
    }
}
void make()
{
    sf("%d %d",&n,&m);
    for(int i=0 ;i<=n ;i++ )
    {
        gh[i].clear();
    }
    st.clear();
    int u,v;
    for(int i=0 ;i<m ;i++ )
    {
        sf("%d%d",&u,&v);
        gh[u].push_back(v);
        gh[v].push_back(u);
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        make();
//        cout << gh[3][0] << gh[3][1] << gh[3][2] << endl;
//        DB;
        ti=1;
        root=1;
        memset(visit,0,sizeof visit);
        for(int i=1 ;i<=n ;i++ )
        {
            if(!visit[i])
            {
                art(i);
            }
        }
//        for(int i=1 ;i<=n ;i++ )
//        {
//            cout << i << ' ' << low[i] << endl;
//        }
//        cout << *st.begin() << endl;
        pf("Case %d: %d\n",qq,st.size());
    }
    return 0;
}
/*
2
5 4
2 1
1 3
5 4
4 1
*/
