#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define DB                    cout<<" **** "<<endl;
#define mod                   1000000007
#define inf                   1000000007
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

#define maxn 1007
vector<pii>gr[maxn],rev[maxn];

int dist[maxn];
struct cmp
{
    bool operator () (const pii &a, const pii &b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    int vist[maxn];
    for(int i=0; i<maxn; i++)
    {
        dist[i] = inf;
        vist[i] = 0;
    }
    priority_queue< pii, vector<pii>, cmp > Q;
    Q.push( make_pair(src,0) );
    dist[src] = 0;
    while(!Q.empty())
    {
        pii u = Q.top();
        Q.pop();
        if(vist[u.fs])
        {
            continue;
        }
        for(int i=0; i<gr[u.fs].size(); i++)
        {
            int v = gr[u.fs][i].fs;
            int w = gr[u.fs][i].sc;
            if(dist[u.fs]+w < dist[v])
            {
                dist[v] = dist[u.fs] + w;
                Q.push( make_pair(v,dist[v]) );
            }
        }
        vist[u.fs]=1;
    }

}

int revd[maxn];
void dijkstra2(int src)
{
    int vist[maxn];
    for(int i=0; i<maxn; i++)
    {
        revd[i] = inf;
        vist[i] = 0;
    }

    priority_queue< pii, vector<pii>, cmp > Q;
    Q.push(make_pair(src,0));
    revd[src] = 0;
    while(!Q.empty())
    {
        int u = Q.top().fs;
        Q.pop();
        if(vist[u])
        {
            continue;
        }
        for(int i=0; i<rev[u].size(); i++)
        {
            int v = rev[u][i].fs;
            int w = rev[u][i].sc;
            if(revd[u]+w < revd[v])
            {
                revd[v] =  revd[u] + w;
                Q.push(make_pair(v,dist[v]));
            }
        }
    }
}
//struct comp
//{
//    bool operator ()(pii &a ,pii &b)
//    {
//        return a.second>b.second;
//    }
//};
//void dijkstra(int src)
//{
//    int distance[maxn];
//    for (int i=1;i<=n ;i++ )
//    {
//        distance[i]=inf;
//        visit[i]=false;
//    }
//    priority_queue<pii,vector<pii>,comp>Q;
//    Q.push(pii(src,0));
//    distance[src]=0;
//    while(!Q.empty())
//    {
//        int u=Q.top().first;
//        Q.pop();
//        if(visit[u])continue;
//        for (int i=0;i<vt[u].size() ;i++ )
//        {
//            int v=vt[u][i].first;
//            int w=vt[u][i].second;
//            if(distance[u]+w<distance[v])
//            {
//                distance[v]=distance[u]+w;
//                Q.push(pii(v,distance[v]));
//            }
//        }
//        visit[u]=true;
//    }
//    if(distance[n]!=inf) pf("%d\n",distance[n]);
//    else pf("Impossible\n");
//}
int main()
{
    int n,m,x;
    sf3(n,m,x);
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        sf3(u,v,w);
        gr[u].push_back( make_pair(v,w) );
        rev[v].push_back( make_pair(u,w) );
    }
    dijkstra(x);

//    cout << "fine " << endl;
//    for(int i=1; i<=n; i++)
//    {
//        cout << i << " --> " << dist[i] << endl;
//    }
//    cout << "first dijkstra sesh " << endl;
    dijkstra2(x);


//    for(int i=1; i<=n; i++)
//    {
//        cout << i << " --> " << revd[i] << endl;
//    }
//    cout << "first dijkstra sesh " << endl;


    int mn=0;
    for(int i=1; i<=n; i++)
    {
         if(i!=x)
        mn=max(mn,dist[i]+revd[i]);
    }
    pf1(mn);
    return 0;

}
/*



*/
