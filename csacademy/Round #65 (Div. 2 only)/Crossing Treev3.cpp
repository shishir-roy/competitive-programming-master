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
vector<int>gr[maxn],node;
int n;
int lvl[maxn];
void dfs(int u,int p)
{
    lvl[u] = lvl[p] + 1;
    for(int v : gr[u])
    {
        if(v != p)
        {
            dfs(v,u);
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
    dfs(1,0);
    int new_root = 0;
    for(int i=1;i<=n;i++)
    {
        if(lvl[i] > lvl[new_root])
        {
            new_root = i;
        }
    }
    dfs(new_root,0);

    int end_root = 0;
    for(int i=1;i<=n;i++)
    {
        if(lvl[i] > lvl[end_root])
        {
            end_root = i;
        }
    }


    return 0;
}
/*



*/
