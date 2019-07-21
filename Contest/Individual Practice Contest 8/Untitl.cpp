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

#define maxn 300007
vector<int>gr[maxn];
int flag[maxn];
int id,cy=0;
void dfs(int u)
{
    for(int i=0;i<gr[u].size();i++)
    {
        int v = gr[u][i];
        if(v==id and flag[v]==1)
        {
            cy=1;
            return;
        }
        if(flag[v]==0)
        {
            dfs(v);
        }
    }
    return;
}
char str[maxn];
int main()
{

    int n,m;
    sf2(n,m);

    sf("%s",str);
    for(int i=0;i<m;i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].push_back(v);
    }
    cout << "input sesh " << endl;
    memset(flag,0,sizeof flag);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            id=i;
            cout << i << " ehd dfs " << endl;
            dfs(i);
        }
    }
    if(cy)
    {
        pf("-1");
    }
    else
    {
        cout << "ok " << endl;
    }
    return 0;
}
/*



*/
