#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
#define mod                   1000000007
#define inf                   INT_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 100007
vector<int>gr[maxn];
vector< pair<int,int> > edge;
int vist[maxn];
int cl=0;
void dfs(int u)
{
    vist[u]=cl;
    for(int v : gr[u])
    {
        if(vist[v]==-1)
        {
//            cout << u << " ---> " << v << endl;
            edge.push_back({u,v});
            dfs(v);
        }
    }
}
int dfs2(int u,int nisi)
{
    vist[u]=-5;
    set<int>st;
    for(int v : gr[u])
    {
        if(v==nisi) continue;
        st.insert(vist[v]);
    }
    for(int v : gr[u])
    {
        auto it = st.find(vist[v]);
        if( it!=st.end())
        {
            if(v==nisi) continue;
            edge.push_back({u,v});
            st.erase(it);
        }
    }
    return st.size();
}
int main()
{
    int n,m;
    sf2(n,m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int s,t,ds,dt;
    sf2(s,t);
    sf2(ds,dt);

    memset(vist,-1,sizeof vist);
    vist[s]=0;
    vist[t]=0;

    for(int i=1; i<=n; i++)
    {
        if(vist[i]==-1)
        {
            cl++;
            dfs(i);
        }
    }

    int a= dfs2(s,t);
    int b= dfs2(t,s);
    if(a>ds || b>dt)
    {
        pf("No\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(vist[i]==-1)
        {
            pf("No\n");
            return 0;
        }
    }
    pf("Yes\n");
    for(int i=0; i<edge.size(); i++)
    {
        pf("%d %d\n",edge[i].fs, edge[i].sc);
    }
    return 0;

}
/*



*/
