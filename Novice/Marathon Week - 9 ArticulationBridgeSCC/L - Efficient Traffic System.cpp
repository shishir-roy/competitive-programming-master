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
#define maxn 20000
int n,e;
int visit[maxn+7],sccnum=1;
vector<int>gh[maxn+7],tgh[maxn+7];
stack<int>st;
void dfs(int u)
{
    visit[u]=1;
    for(int i=0 ; i<gh[u].size() ; i++ )
    {
        int v=gh[u][i];
        if(!visit[v])
        {
            dfs(v);
        }
    }
    st.push(u);
}
void dfss(int u)
{
    visit[u]=sccnum;
    for(int i=0 ; i<tgh[u].size() ; i++ )
    {
        int v=tgh[u][i];
        if(!visit[v])
        {
            dfss(v);
        }
    }
}
void scc()
{
    memset(visit,0,sizeof visit);
    while(!st.empty()) st.pop();
    for(int i=1 ; i<=n ; i++ )
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    memset(visit,0,sizeof visit);
    sccnum=1;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!visit[u])
        {
//            cout << u << sccnum << endl;
            dfss(u);
            sccnum++;
        }
    }
}
int dag()
{
//    cout << "scc num " << sccnum << endl;
    if(sccnum==2) return 0;
    int x,y;
    int in[maxn+7],out[maxn+7];
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    for(int u=1 ; u<=n ; u++ )
    {
        for(int j=0 ; j<gh[u].size() ; j++ )
        {
            int v=gh[u][j];
            x=visit[u],y=visit[v];
            if(x==y) continue;
            in[y]++,out[x]++;
        }
    }
    int ii=0,oo=0;
//    for(int i=1 ; i<=5 ; i++ )
//    {
//        cout << i << " sccnum " << visit[i] << endl;
//    }
//    cout << "scc num " << sccnum << endl;
    for(int i=1 ; i<sccnum ; i++ )
    {
        if(in[i]==0)
        {
//            cout << "indegree " << i << endl;
            ii++;
        }
        if(out[i]==0)
        {
//            cout << "outdegree " << i << endl;
            oo++;
        }
    }
//    cout << ii << endl;
//    cout << oo << endl;
    return max(ii,oo);
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        sf("%d%d",&n,&e);
        for(int i=0 ; i<=n ; i++ )
        {
            gh[i].clear();
            tgh[i].clear();
        }
        int u,v;
        for(int i=0 ; i<e ; i++ )
        {
            sf("%d %d",&u,&v);
            gh[u].push_back(v);
            tgh[v].push_back(u);
        }
        scc();
        int t=dag();
        pf("Case %d: %d\n",qq,t);
    }
    return 0;
}
/*
1

4 4
1 2
2 3
3 2
1 4
*/
