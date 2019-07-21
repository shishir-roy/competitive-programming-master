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
int ara[maxn];
multiset<int>tree[4*maxn];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id].insert(ara[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].insert( tree[id*2].begin(), tree[id*2].end() );
    tree[id].insert( tree[id*2+1].begin(), tree[id*2+1].end() );
}

void updt(int id,int l,int r,int ql,int qr,int pval,int cval)
{
    if(r<ql || l>qr) return ;
    auto it=tree[id].find(pval);
    tree[id].erase(it);
    tree[id].insert(cval);
    if(l==r)
    {
        return ;
    }
    int mid = (l+r)/2;
    updt(id*2,l,mid,ql,qr,pval,cval);
    updt(id*2+1,mid+1,r,ql,qr,pval,cval);
}

ll query(int id,int l,int r,int ql,int qr,int val)
{
    if(r<ql || l>qr) return INT_MIN;
    if(l>=ql and r<=qr)
    {
        ll a=INT_MIN, b=INT_MIN;
        auto it=tree[id].upper_bound(val);
        if(it!=tree[id].end()) a= 1LL*(*it-ara[ql])*(ara[qr]-*it);
        if(it!=tree[id].begin()) --it, b =1LL*(*it-ara[ql])*(ara[qr]-*it);
        return max(a,b);
    }
    int mid= (l+r)/2;
    return max ( query(id*2,l,mid,ql,qr,val), query(id*2+1,mid+1,r,ql,qr,val) );
}
int main()
{
    int tc;
    sf1(tc);
    while(tc--)
    {
        for(int i=0;i<4*maxn;i++) tree[i].clear();
        int n,q;
        sf2(n,q);
        for(int i=1;i<=n;i++)
            sf1(ara[i]);
        build(1,1,n);
        while(q--)
        {
            int type,x,y;
            cin >> type >> x >> y;
            if( type == 1)
            {
                cout << query(1,1,n,x,y,(ara[x]+ara[y])/2 ) << endl;
            }
            else
            {
                updt(1,1,n,x,x,ara[x],y);
                ara[x]=y;
            }
        }
    }
    return 0;
}
/*
1
4 3
2 1 4 3
1 1 4
2 2 3
1 1 3


*/
