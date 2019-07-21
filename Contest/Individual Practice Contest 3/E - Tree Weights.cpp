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
int st[maxn],ft[maxn],dep[maxn],is_child[maxn];
int tim=0;

ll bigmod(ll b,ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1)  ans = (ans*b) % mod;
        p>>=1;
        b = (b*b) % mod;
    }
    return ans;
}
void dfs(int u,int p,int h)
{
    dep[u] = h;
    st[u] = ++tim;
    int f=0;
    for(int v : gr[u])
    {
        if(v != p)
        {
            f=1;
            dfs(v,u,dep[u]+1);
        }
    }

    if(!f)
    {
        is_child[u] = 1;
    }
    ft[u] = tim;
}

ll tree[10*maxn];
void updt(int id,int l,int r,int ps,ll val)
{
    if(l == r)
    {
        tree[id]+=val;
        return ;
    }
    int mid = (l+r)/2;
    if(ps<=mid)
    {
        updt(id*2,l,mid,ps,val);
    }
    else
    {
        updt(id*2+1,mid+1,r,ps,val);
    }

    tree[id] = ( tree[id*2] + tree[id*2+1] + mod )%mod;
}

ll query(int id,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
    {
        return 0;
    }
    if(l>=ql and r<=qr)
    {
        return tree[id];
    }

    int mid = (l+r)/2;
    return ( query(id*2,l,mid,ql,qr) + query(id*2+1,mid+1,r,ql,qr) ) % mod;
}

void clr()
{
    for(int i=0; i<maxn; i++)
    {
        gr[i].clear();
    }
    tim = 0;
    memset(tree,0,sizeof tree);
}

int main()
{
    ll two[maxn+7];
    two[0] = 1LL;
    for(int i=1; i<maxn; i++)
    {
        two[i] = (two[i-1]*2LL) % mod;
    }
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    sf1(tc);
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        sf1(n);
        clr();
        for(int i=0; i<n-1; i++)
        {
            int u,v;
            sf2(u,v);
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1,-1,0);
        int s = st[1];
        int e = ft[1];

//        cout << s << " " << e << endl;
        int q;
        pcase(qq);
        sf1(q);
        while(q--)
        {
            int ty;
            sf1(ty);
            if(ty == 2)
            {
                ll u,x;
                sf2ll(u,x);

                ll val = ( x*two[dep[u]-1] ) % mod;
                updt(1,s,e,st[u],val);
            }
            else
            {
                ll u;
                sf1(u);

                if(is_child[u])
                {
                    ll x = query(1,s,e,st[u],ft[u]) ;
                    ll d = two[dep[u]-1];

                    ll t = ( x * bigmod(d,mod-2) + mod ) % mod;
                    pf1ll(t);
                }
                else
                {
                    ll x = query(1,s,e,st[u],ft[u]) ;
                    ll d = two[dep[u]];
                    ll t = ( x * bigmod(d,mod-2) + mod ) % mod;
                    pf1ll(t);
                }
            }
        }
    }

    return 0;
}
/*



*/
