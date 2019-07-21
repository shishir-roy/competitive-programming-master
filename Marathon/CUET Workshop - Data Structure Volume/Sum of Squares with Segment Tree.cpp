#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 1000000

pair<int,int> tree[maxn*4];
pair<int,int> lazy[4*maxn];
int ara[maxn+500];

void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id].first=ara[l]*ara[l];
        tree[id].second=ara[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].first=tree[id*2].first+tree[id*2+1].first;
    tree[id].second=tree[id*2].second+tree[id*2+1].second;
}

void shift(int id,int l,int r)
{
    if(l!=r)
    {
        int mid=(l+r)/2;
        
        if(lazy[id].first)
        {
            tree[id*2].first=tree[id*2].first+2LL*lazy[id].first*tree[id*2].second+(mid-l+1)*lazy[id].first*lazy[id].first;
            tree[id*2].second+=(mid-l+1)*lazy[id].first;
            
            tree[id*2+1].first=tree[id*2+1].first+2LL*lazy[id].first*tree[id*2+1].second+(r-mid)*lazy[id].first*lazy[id].first;
            tree[id*2].second+=(r-mid+1)*lazy[id].first;
            
            lazy[id].first=0;
        }
        
        if(lazy[id].second)
        {
            tree[id*2].first=(mid-l+1)*lazy[id].second*lazy[id].second;
            tree[id*2].second=(mid-l+1)*lazy[id].second;
            
            tree[id*2+1].first=(r-mid)*lazy[id].second*lazy[id].second;
            tree[id*2].second=(r-mid+1)*lazy[id].second;
            
            lazy[id].second=0;
        }
    }
    return;
}
void updt(int id,int l,int r,int ql,int qr,int typ,int val)
{
    if(r<ql || l>qr) return;
    shift(id,l,r);
    if(l>=ql and r<=qr)
    {
        if(typ==1)
        {
            tree[id].first=tree[id].first+2LL*val*tree[id].second+(r-l+1)*val*val;
            tree[id].second+=1LL*(r-l+1)*val;
            lazy[id].first+=1LL*val;
        }
        else if(typ==0)
        {
            tree[id].first=1LL*(r-l+1)*val*val;
            tree[id].second=1LL*(r-l+1)*val;
            lazy[id].second=val;
        }
        return;
    }
    int mid=(l+r)/2;
    updt(id*2,l,mid,ql,qr,typ,val);
    updt(id*2+1,mid+1,r,ql,qr,typ,val);
    tree[id].first=tree[id*2].first+tree[id*2+1].first;
    tree[id].second=tree[id*2].second+tree[id*2+1].second;
}

int query(int id,int l,int r,int ql,int qr)
{
    if(r<ql || l>qr) return 0;
    if(l>=ql and r<=qr)
    {
        return tree[id].first;
    }
    int mid=(l+r)/2;
    return ( query(id*2,l,mid,ql,qr) + query(id*2+1,mid+1,r,ql,qr) );
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        printf("Case %d:\n",qq);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        while(m--)
        {
            int typ;
            scanf("%d",&typ);
            if(typ==2)
            {
                int l,r;
                scanf("%d %d",&l,&r);
                printf("%d\n",query(1,1,n,l,r));
            }
            else if(typ==1)
            {
                int l,r,x;
                scanf("%d %d %d",&l,&r,&x);
                updt(1,1,n,l,r,typ,x);
            }
            else
            {
                int l,r,x;
                scanf("%d %d %d",&l,&r,&x);
                updt(1,1,n,l,r,typ,x);
            }
        }
    }
    return 0;
}