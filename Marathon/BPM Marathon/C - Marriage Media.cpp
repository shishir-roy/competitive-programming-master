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

#define maxn 57
struct data
{
    int h,age,c;
};
vector<int>gr[maxn];
int Left[maxn], Right[maxn];
bool vist[maxn];

bool dfs(int u)
{
    if(vist[u]) return 0;
    vist[u] = 1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v = gr[u][i];
        if(Right[v] == -1)
        {
            Right[v] = u;
            Left[u] = v;
            return 1;
        }
    }
    for(int i=0;i<gr[u].size();i++)
    {
        int v = gr[u][i];
        if( dfs(Right[v]) )
        {
            Right[v] = u;
            Left[u] = v;
            return 1;
        }
    }
    return 0;
}

int matching()
{
    memset(Left,-1,sizeof Left);
    memset(Right,-1,sizeof Right);
    bool done ;
    do{
        done = 1;
        memset(vist,0,sizeof vist);
        for(int i=0;i<maxn;i++)
        {
            if(Left[i] == -1 && dfs(i) )
            {
                done = 0;
            }
        }
    }while(!done);

    int ret = 0;
    for(int i=0;i<maxn;i++)
    {
        ret += (Left[i] != -1);
    }
    return ret;
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    sf1(tc);
    for(int qq=1;qq<=tc;qq++)
    {
        for(int i=0;i<maxn;i++)
        {
            gr[i].clear();
        }
        int m,w;
        sf2(m,w);

        data ara[m+7];
        for(int i=0;i<m;i++)
        {
            sf3(ara[i].h, ara[i].age, ara[i].c );
        }

        data ara2[w+7];
        for(int i=0;i<w;i++)
        {
            sf3(ara2[i].h, ara2[i].age, ara2[i].c);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<w;j++)
            {
                if( abs(ara[i].h-ara2[j].h)<=12 and abs(ara[i].age-ara2[j].age)<=5 and ara[i].c==ara2[j].c)
                {
                    gr[i].push_back(j);
                }
            }
        }

        int ans = matching();
        pcase(qq);
        pf1(ans);
    }

    return 0;
}
/*



*/
