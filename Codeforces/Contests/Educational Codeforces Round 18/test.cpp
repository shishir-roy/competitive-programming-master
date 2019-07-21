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
#define pf1(a)                printf("%d ",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 200007
set<int>gr[maxn];
int flag[maxn],cnt=0,n;
void dfs(int u)
{
    flag[u]=1;
    cnt++;
    for(int i=1;i<=n;i++)
    {
        auto it = gr[u].find(i);
        if(it!=gr[u].end())
        {
            continue;
        }
        if(flag[i]==0)
        {
            cout << u << " --> " << i << endl;
            dfs(i);
        }
    }
}
int main()
{
    int m;
    sf2(n,m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].insert(v);
        gr[v].insert(u);
    }
    vector<int>vt;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            cnt=0;
            dfs(i);
            vt.push_back(cnt);
        }
    }
    sort(vt.begin(),vt.end());
    cout << vt.size() << endl;
    for(int x : vt)
    {
        pf1(x);
    }
    return 0;
}
/*



*/
