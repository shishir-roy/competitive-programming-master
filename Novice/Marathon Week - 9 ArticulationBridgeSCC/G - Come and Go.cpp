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
#define maxn 2009
vector<int>gh[maxn],tgh[maxn];
int n,m,u,v,w;
int visit[maxn],marking[maxn];
stack<int>st;
void dfs(int u)
{
    visit[u]=1;
    for(int i=0 ;i<gh[u].size() ;i++ )
    {
        int v=gh[u][i];
        if(!visit[v])
        {
            dfs(v);
        }
    }
    st.push(u);
}
void dfss(int u,int mark)
{
    visit[u]=1;
    marking[u]=mark;
    for(int i=0 ;i<tgh[u].size() ;i++ )
    {
        int v=tgh[u][i];
        if(!visit[v])
        {
            dfss(v,mark);
        }
    }
}
void scc()
{
    memset(visit,0,sizeof visit);
    while(!st.empty())st.pop();
    for(int i=1 ;i<=n ;i++ )
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    memset(visit,0,sizeof visit);
    memset(marking,0,sizeof marking);
    int mark=0;
//    stack<int>::iterator it;
//    it=st.begin()
//    for( ; it!=st.end():it++ )
//    {
//        cout << it << endl;
//    }
//    DB;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!visit[u])
        {
            dfss(u,mark++);
        }
    }
    if(mark>1) cout << "0" << '\n';
    else cout << "1" << '\n';
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(sf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0) break;
        for(int i=0 ;i<=n ;i++ )
        {
            gh[i].clear();
            tgh[i].clear();
        }
        for(int i=0 ; i<m ; i++ )
        {
//            DB;
            sf("%d %d %d",&u,&v,&w);
            if(w==1)
            {
                gh[u].push_back(v);
                tgh[v].push_back(u);
            }
            else
            {
                gh[u].push_back(v);
                gh[v].push_back(u);
                tgh[u].push_back(v);
                tgh[v].push_back(u);
            }
        }
//        DB;
        scc();
    }
    return 0;
}
/*

*/
