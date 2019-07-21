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
bool cmp(const pair<int,pii>a,const pair<int,pii>b)
{
    return a.sc.sc < b.sc.sc;
}
int par[maxn];
int root(int u)
{
    if(par[u]==u) return u;
    return par[u]=root(par[u]);
}
void add(int u,int v)
{
    int ru = root(u);
    int rv = root(v);
    par[ru]=rv;
}
bool fin(int u,int v)
{
    int ru = root(u);
    int rv = root(v);
    return ru==rv;
}
int flag[maxn],st[maxn],ed[maxn],tim=1,dd[maxn];
void dfs(int u)
{
    dd[u] = 1;
    st[u]=tim++;
    for(int v : gr[u])
    {
        if(dd[v]==0)
        dfs(v);
    }
    ed[u]=tim++;
}
int main()
{
    vector< pair<int,pii> >edge,q;
    int n,m;
    sf2(n,m);
    int pack=1,qn=1;
    for(int i=1;i<=m;i++)
    {
        int typ;
        sf1(typ);
        if(typ==1)
        {
            int u,v;
            sf2(u,v);
            gr[v].push_back(u);
            flag[v] = 1;
            edge.push_back( {1,{u,v}} );
        }
        else if(typ==2)
        {
            int d;
            sf1(d);///d ke pack no document dawya hoiche
            edge.push_back( {2,{d,pack++}} );
        }
        else
        {
            int x,d;
            sf2(x,d);/// x ke d pack ta dawya hoiche kina
            q.push_back( {qn++,{x,d}} );
        }
    }





    sort(q.begin(),q.end(),cmp);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==1 and dd[i]==0)
        {
            dfs(i);
        }
        par[i] = i;
    }

//    for(int i=1;i<=4;i++)
//    {
//        cout << i << " er " << st[i] << " " << ed[i] << endl;
//    }


    int ans[maxn];
    memset(ans,-1,sizeof ans);
    int j=0;

    for(int i=0;i<edge.size();i++)
    {
        int typ=edge[i].fs;
        if(typ==1)
        {
//            cout << edge[i].sc.fs << " of type 1 " << edge[i].sc.sc << endl;
            add(edge[i].sc.fs,edge[i].sc.sc);
        }
        else
        {
            int p = edge[i].sc.fs;
            int pack = edge[i].sc.sc;
            int rp = root(p);
            for(;j<q.size();j++)
            {
                if(q[j].sc.sc != pack) break;

                int t = q[j].sc.fs;
//                cout << rp << " " << t << " connection " << fin(rp,t) << endl;
                if(fin(rp,t)==0)
                {
//                    cout << "first no" << endl;
                    ans[q[j].fs] = 0;
                }
                else
                {
                    if(st[t]<=st[p] and ed[t]>=ed[p])
                    {
                        ans[q[j].fs] = 1;
                    }
                    else
                    {
//                        cout << "second no " << endl;
                        ans[q[j].fs] = 0;
                    }
                }
            }
        }
    }

    for(int i=1;i<qn;i++)
    {
        if(ans[i]==0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
/*



*/
