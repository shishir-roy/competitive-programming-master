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

ll tree[4*maxn];
int ara[maxn];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id] = ara[l];
        return ;
    }

    int mid = (l+r) / 2 ;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id] = max(tree[id*2],tree[id*2+1]);
}

ll lazy[4*maxn];
void shift(int id,int l,int r)
{
    if(l != r)
    {
        tree[id*2] = tree[id*2+1] = lazy[id];
        lazy[id*2] = lazy[id*2+1] = lazy[id];
        lazy[id] = 0 ;
    }
}

void updt(int id,int l,int r,int ql,int qr,ll val)
{
    if(l>qr || r<ql) return;
    if(lazy[id])
    {
        shift(id,l,r);
    }
    if(l>=ql && r<=qr)
    {
        lazy[id] = tree[id] = val;
        return ;
    }

    int mid = (l+r) / 2;
    updt(id*2,l,mid,ql,qr,val);
    updt(id*2+1,mid+1,r,ql,qr,val);

    tree[id] = max(tree[id*2],tree[id*2+1]);
}

ll query(int id,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
    {
        return -1LL;
    }
    if(lazy[id])
    {
        shift(id,l,r);
    }
    if(l>=ql and r<=qr)
    {
//        cout << l << " --> " << r << endl;
        return tree[id];
    }

    int mid = (l+r) / 2;
    return max( query(id*2,l,mid,ql,qr), query(id*2+1,mid+1,r,ql,qr) );
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    sf1(n);
    for(int i=1; i<=n; i++)
    {
        sf1(ara[i]);
    }
    build(1,1,n);

//    cout << tree[1] << " " << tree[2] << "  " << tree[1*2+1] << endl;
    int q;
    sf1(q);
    while(q--)
    {
        ll w,h;
        sf2ll(w,h);
        ll val = query(1,1,n,1,w);
        pf1ll(val);
        updt(1,1,n,1,w,val+h);
    }
    return 0;
}
/*



*/
