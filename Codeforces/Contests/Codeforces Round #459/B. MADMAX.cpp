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
vector<int>gr[500],wt[500];

int dp[500][500][50][5];

int rec(int u,int v,int pre,int mv)
{
    int &ret=dp[u][v][pre][mv];
    if(ret != -1)
    {
        return ret;
    }
    ret=0;
    if(mv==1)
    {
        for(int i=0;i<gr[u].size();i++)
        {
            int x = gr[u][i];
            int y = wt[u][i];
            if(y>=pre)
            {
                ret |= ( 1-rec(x,v,y,2) );
            }
        }
    }
    else
    {
        for(int i=0;i<gr[v].size();i++)
        {
            int x = gr[v][i];
            int y = wt[v][i];
            if(y>=pre)
            {
                ret |= ( 1-rec(u,x,y,1) );
            }
        }
    }
    return ret;
}
int main()
{
    int n,m;
    sf2(n,m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        char ch;
        sf2(a,b);
        sf(" %c",&ch);
        int t = ch-'a'+1;
        gr[a].push_back(b);
        wt[a].push_back(t);
    }

    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(rec(i,j,0,1))
            {
                pf("A");
            }
            else
            {
                pf("B");
            }
        }
        pf("\n");
    }
    return 0;
}
/*



*/
