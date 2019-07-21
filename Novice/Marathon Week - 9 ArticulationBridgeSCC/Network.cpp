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
#define maxn 107
vector<int>gh[maxn];
int root,ti;
int n;
set<int>st;
int d[maxn],low[maxn],parent[maxn];
bool visit[maxn];
void art(int u)
{
    d[u]=ti;
    low[u]=ti;
    ti++;
    visit[u]=1;
    int child=0;
    for(int i=0 ; i<gh[u].size() ; i++ )
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
            art(v);
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
    for(int i=0 ; i<=n ; i++ )
    {
        gh[i].clear();
    }
    st.clear();
    while(1)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        int u,v;
        ss>>u;
//        cout << "u " << u << endl;
        if(u==0)
            return;
        while(ss>>v)
        {
//            cout << v << ' ';
            gh[u].push_back(v);
            gh[v].push_back(u);
        }
//        cout << '\n';
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(sf("%d",&n)==1)
    {
        if(n==0)
        {
//            pf("\n");
            return 0;
        }
        getchar();
        make();
        root=1;
        ti=1;
        memset(visit,0,sizeof visit);
        art(1);
        cout << (int)st.size() << '\n';
    }
    return 0;
}
/*
5
1 2 3 4 5
2 5
3 5
0
4
1 2 3
3 4
0
4
1 2 3
3 4
0
4
1 2 3
3 4
2 4
0
4
1 2 3
3 4
0
5
1 3 4
2 3 4
3 4
4 5
0
*/
