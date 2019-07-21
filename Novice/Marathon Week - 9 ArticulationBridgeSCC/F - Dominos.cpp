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
#define maxn 100007
vector<int>gh[maxn];
int visit[maxn];
stack<int>s;
void dfs(int u)
{
    visit[u]=0;
    for(int i=0 ;i<gh[u].size() ;i++ )
    {
        int v=gh[u][i];
        if(visit[v]==-1)
        {
            dfs(v);
        }
    }
    s.push(u);
}
void Dfs(int u)
{
    visit[u]=0;
    for(int i=0 ;i<gh[u].size() ;i++ )
    {
        int v=gh[u][i];
        if(visit[v]==-1)
        {
            dfs(v);
        }
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
        int n,m,u,v;
        sf("%d %d",&n,&m);
//        DB;
//        cout << n <<' ' <<  m << endl;
        for(int i=0 ;i<=n ;i++ )
        {
            gh[i].clear();
        }
        for(int i=0 ;i<m ;i++ )
        {
            sf("%d %d",&u,&v);
            gh[u].push_back(v);
//            gh[v].push_back(u);
        }
        memset(visit,-1,sizeof visit);
        int cnt=0;
        for(int i=1 ;i<=n ;i++ )
        {
            if(visit[i]==-1)
            {
                dfs(i);
            }
        }
        memset(visit,-1,sizeof visit);
        while(!s.empty())
        {
            int u=s.top();
            s.pop();
            if(visit[u]==-1)
            {
                Dfs(u);
                cnt++;
            }
        }
        pf("%d\n",cnt);
    }
    return 0;
}
/*
8
10 3
3 10
9 10
7 2
*/
