#include<bits/stdc++.h>
using namespace std;

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d:\n",x)
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
struct data
{
    int val, ps;
};
bool cmp(const data &a,const data &b)
{
    if(a.val != b.val) return a.val > b.val;
    return a.ps < b.ps;
}

data ara[maxn];
int temp[maxn];

int tree[4*maxn];
void updt(int id,int l,int r,int ql,int val)
{
    if(l==r)
    {
        tree[id] = val;
        return;
    }
    int mid = (l+r)/2;
    if(ql <= mid)
    {
        updt(id*2,l,mid,ql,val);
    }
    else
    {
        updt(id*2+1,mid+1,r,ql,val);
    }

    tree[id] = max( tree[id*2], tree[id*2+1] );
}

int query(int id,int l,int r,int ql,int qr)
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
    return max( query(id*2,l,mid,ql,qr), query(id*2+1,mid+1,r,ql,qr) );
}
int main()
{
    int tc;
    sf1(tc);
    for(int qq=1;qq<=tc;qq++)
    {
        int n, q;
        sf2(n,q);
        for(int i=0;i<n;i++)
        {
            sf1(ara[i].val);
            ara[i].ps = i;
            temp[i] = ara[i].val;
        }
        sort(ara,ara+n,cmp);

        for(int i=0;i<4*maxn;i++)
        {
            tree[i] = 0;
        }
        int lis[maxn];
        for(int i=0;i<n;i++)
        {
            int temp = query(1,0,n-1,ara[i].ps,n-1);
            temp++;
            lis[ara[i].ps] = temp;
            updt(1,0,n-1,ara[i].ps,temp);
        }
        pcase(qq);
        while(q--)
        {
            int m;
            sf1(m);

            int prev = -1000000000, f=0;
            for(int i=0;i<n;i++)
            {
                if(lis[i]>=m and prev < temp[i])
                {
                    if(f)
                    {
                        pf(" %d",temp[i]);
                    }
                    else
                    {
                        pf("%d",temp[i]);
                    }
                    f=1;
                    prev = temp[i];
                    m--;
                    if(m==0)
                    {
                        break;
                    }
                }
            }
            if(m>0)
            {
                pf("Impossible");
            }
            pf("\n");
        }
    }

    return 0;
}
/*



*/
