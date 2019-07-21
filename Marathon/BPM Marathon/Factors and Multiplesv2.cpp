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

#define maxn 107

#define SET(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
vector<int>gr[maxn];

bool vist[maxn];
int Left[maxn], Right[maxn];

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

int match(int n)
{
    SET(Left);
    SET(Right);

    int i, ret = 0;
    bool done;
    for(int i=0;i<n;i++)
    {
        CLR(vist);
        for(int j=0;j<n;j++)
        {
            if(dfs(j));
        }
    }
    for(int i=0;i<n;i++)
    {
        ret+= (Left[i] != -1);
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

        int n;
        sf1(n);
        vector<int>l;
        for(int i=0;i<n;i++)
        {
            int t;
            sf1(t);
            l.push_back(t);
        }

        int m;
        sf1(m);
        vector<int>r;
        for(int i=0;i<m;i++)
        {
            int t;
            sf1(t);
            r.push_back(t);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(l[i]!=0 and r[j]%l[i]==0)
                {
                    gr[i].push_back(j);
                }
            }
        }

        int ans = match(n);
        pcase(qq);
        pf1(ans);
//        cout << ans << endl;
    }

    return 0;
}
/*



*/
