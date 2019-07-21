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
vector<string>vt;
set<int>st;
int n,r,num;
map<string,int>mp;
bool visit[maxn];
int parent[maxn],d[maxn],low[maxn],root,ti;
void art(int u)
{
    visit[u]=1;
    d[u]=low[u]=ti++;
    int child=0;
    for(int i=0 ;i<gh[u].size() ;i++ )
    {
        int v=gh[u][i];
        if(v==parent[u]) continue;
        else if(visit[v])
        {
            low[u]=min(low[u],d[v]);
        }
        else
        {
            parent[v]=u;
            art(v);
            child++;
            low[u]=min(low[u],low[v]);
            if(d[u]<=low[v] and u!=root)
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
    mp.clear();
    st.clear();
    for(int i=0 ;i<=n ;i++ )
    {
        gh[i].clear();
    }
    string u,v;
    num=1;
    for(int i=0 ;i<n ;i++ )
    {
        cin >> u;
        mp[u]=num++;
    }
    sf("%d",&r);
    for(int i=0 ;i<r ;i++ )
    {
        cin >> u >> v;
        gh[mp[u]].push_back(mp[v]);
        gh[mp[v]].push_back(mp[u]);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int qq=1;
    while(sf("%d",&n) && n!=0)
    {
        make();
        memset(visit,0,sizeof visit);
        ti=1;
        for(int i=1 ;i<num ;i++ )
        {
            if(!visit[i])
            {
//                cout << "root are " << i << endl;
                root=i;
                art(i);
            }
        }
        map<string,int>::iterator itt;
        vt.clear();
        for(auto it:st )
        {
            for(itt=mp.begin();itt!=mp.end();itt++)
            {
                if(itt -> second==it)
                {
                    vt.push_back(itt->fs);
                }
            }
        }
        if(qq!=1) pf("\n");
        pf("City map #%d: %d camera(s) found\n",qq++,st.size());
        sort(vt.begin(),vt.end(),[](string a,string b) { return a<b; } );
        for(auto it: vt )
        {
            cout << it << '\n';
        }
    }
    return 0;
}
/*

*/
