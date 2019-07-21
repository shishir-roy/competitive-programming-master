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
#define maxn 100000
vector<int>gr[maxn],node;
int vist[maxn],cnt=0,n;
int ok =0;
void dfs(int u,int p)
{
    vist[u] = 1;
    cnt++;
    if(cnt <= n)
    {
        ok++;
        node.push_back(u);
    }
    for(int v : gr[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            if(cnt < n)
            {
                ok++;
                node.push_back(u);
            }
        }
    }
}

int vist1[maxn];
void dfs1(int u,int p)
{
    vist1[u] = 1;
    cnt++;
    if(cnt <= n)
    {
        pf("%d ",u);
    }
    for(int v : gr[u])
    {
        if(v!=p)
        {
            dfs1(v,u);
            if(cnt < n)
            {
                pf("%d ",u);
            }
        }
    }
}
int main()
{
    sf1(n);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int mn=maxn+7,id=-1;
    for(int i=1; i<=n; i++)
    {
        if(gr[i].size()<mn)
        {
            mn=gr[i].size();
            id=i;
        }
    }
    dfs(id,-1);
    cnt=0;
    pf1(ok-1);
    dfs1(id,-1);

//    pf1(node.size()-1);
//    for(int x : node)
//    {
//        pf("%d ",x);
//    }
    return 0;
}
/*



*/
