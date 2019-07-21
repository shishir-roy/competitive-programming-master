#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define DB                    cout<<" **** "<<endl;
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
#define pf1(a)                printf("%d",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)
#define level 18
#define maxn 100007

vector<pii>tree[maxn];
int depth[maxn];
int parent[maxn][20];
ll cost[maxn];
int vist[maxn];
void dfs(int u)
{
    for(int i=0; i<tree[u].size(); i++)
    {
        int v = tree[u][i].fs;
        if(vist[v] == -1)
        {
            vist[v] = 1;
//            cout << u << " ---> " << v << endl;
            parent[v][0] = u;
            depth[v] =  depth[u] + 1;
            cost[v] = cost[u] + tree[u][i].sc;
            dfs(v);
        }
    }
}

void pre(int n)
{
    for(int i=1; i<level; i++)
    {
        for(int node=0; node<n; node++)
        {
            if( parent[node][i-1] != -1)
            {
                parent[node][i] =  parent[ parent[node][i-1] ] [i-1];
            }
        }
    }
}

bool is_par(int u,int v)
{
    if(depth[v] < depth[u])
    {
        swap(u,v);
    }

    int diff =  depth[v] - depth[u];

    for(int i=0; i<level; i++)
    {
        if( (diff>>i)&1 )
        {
            v = parent[v][i];
        }
    }
    if(u==v)
    {
        return 1;
    }
    return 0;
}
int lca(int u,int v)
{
    if(depth[v] < depth[u])
    {
        swap(u,v);
    }

    int diff =  depth[v] - depth[u];

    for(int i=0; i<level; i++)
    {
        if( (diff>>i)&1 )
        {
            v = parent[v][i];
        }
    }
    if(u==v)
    {
        return u;
    }

    for(int i=level-1; i>=0; i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main()
{
    int n;
    while(sf1(n))
    {
        if(n==0)
        {
            return 0;
        }
        for(int i=0; i<maxn; i++)
        {
            tree[i].clear();
        }
        memset(parent,-1,sizeof parent);
        memset(depth,0,sizeof depth);
        memset(cost,0,sizeof cost);

        for(int i=1; i<=n-1; i++)
        {
            int x,w;
            sf2(x,w);
            tree[i].push_back(pii(x,w));
            tree[x].push_back(pii(i,w));
        }

        memset(vist,-1,sizeof vist);
        vist[0]=1;
        cost[0]=0;
//         depth[0]
        dfs(0);
        pre(n);
//        for(int i=0; i<n; i++)
//        {
//            cout <<i << " --> " << cost[i] << endl;
//        }
//         cout << "lca " << lca(2,3) << endl;
        int q,f=0;
        sf1(q);
        while(q--)
        {
            int u,v;
            sf2(u,v);
            int l = lca(u,v);
            if(f)
            {
                pf(" ");
            }
            f=1;
            if(is_par(u,v))
            {
                pf1ll(abs(cost[v]-cost[u]));
            }
            else
            {
                pf1ll(cost[u]+cost[v]-2*cost[l]);
            }

        }
        pf("\n");
    }
    return 0;

}
/*
6
0 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
1
5 0


*/
