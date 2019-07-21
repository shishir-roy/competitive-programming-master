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
#define maxn 300000
int n,m;
int val[maxn];

class data
{
public:
    int ara[maxn];
    int tree[maxn*5],lazy[maxn*5];
    void clr()
    {
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        memset(ara,0,sizeof ara);
    }
    void build(int id,int l,int r)
    {
        if(l==r)
        {
            tree[id] = val[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    void shift(int id,int l,int r)
    {
        if(l != r)
        {
            tree[id*2]+=lazy[id];
            tree[id*2+1]+=lazy[id];
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
            lazy[id] = 0 ;
        }
    }
    void updt(int id,int l,int r,int ql,int qr,int v)
    {
        if(lazy[id])
        {
            shift(id,l,r);
        }
        if(l>qr || r<ql)
        {
            return ;
        }
        if(l>=ql and r<=qr)
        {
            tree[id]+= v;
            lazy[id]+=v;
            return ;
        }
        int mid = (l+r)/2;
        updt(id*2,l,mid,ql,qr,v);
        updt(id*2+1,mid+1,r,ql,qr,v);
        tree[id] =  tree[id*2] + tree[id*2+1];
    }

    int query(int id,int l,int r,int ql,int qr)
    {
        if(lazy[id])
        {
            shift(id,l,r);
        }
        if(l>qr || r<ql)
        {
            return 0;
        }
        if(l>=ql and r<=qr)
        {
            return tree[id];
        }
        int mid = (l+r)/2;
        int a1 = query(id*2,l,mid,ql,qr);
        int a2 = query(id*2+1,mid+1,r,ql,qr);
        tree[id]= tree[id*2] + tree[id*2+1];
        return a1 + a2 ;
    }
};

data odd,even;

vector<int>gr[maxn];
int lvl[maxn],bgn[maxn],ed[maxn],tim=0;
void dfs(int u,int p)
{
    tim++;
    lvl[u] = lvl[p] + 1;
    if(lvl[u]%2 == 1)
    {
        odd.ara[tim] = val[u];
    }
    else
    {
        even.ara[tim] = val[u];
    }
    bgn[u] = tim;

    for(int v : gr[u])
    {
        if(v != p)
        {
            dfs(v,u);
        }
    }
    ed[u] = tim;
}
int main()
{
    odd.clr();
    even.clr();


    sf2(n,m);
    for(int i=1; i<=n; i++)
    {
        sf1(val[i]);
    }
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1,0);

//    for(int i=1; i<=10; i++)
//    {
//        cout << i << " --> " << odd.ara[i] << " " << even.ara[i] << endl;
//    }
//    cout << endl << endl;
    odd.build(1,1,tim);
//    cout << endl;
    even.build(1,1,tim);

    while(m--)
    {
        int typ;
        sf1(typ);
        if(typ==1)
        {
            int x,v;
            sf2(x,v);
            if(lvl[x]%2 ==1)
            {
                odd.updt(1,1,tim,bgn[x],ed[x],v);
                even.updt(1,1,tim,bgn[x],ed[x],-1*v);
            }
            else
            {
                odd.updt(1,1,tim,bgn[x],ed[x],-1*v);
                even.updt(1,1,tim,bgn[x],ed[x],v);
            }
        }
        else
        {
            int x;
            sf1(x);
            if(lvl[x]%2 == 1)
            {
                int ans = odd.query(1,1,tim,bgn[x],bgn[x]);
                pf1(ans);
            }
            else
            {
                int ans = even.query(1,1,tim,bgn[x],bgn[x]);
                pf1(ans);
            }
        }
    }
    return 0;
}
/*



*/
