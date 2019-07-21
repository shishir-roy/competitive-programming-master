#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 100007
#define mod 1000000007
struct data
{
    int val=0,ps=0;
};
data ara[maxn];
bool cmp(const data a,const data b)
{
    if(a.val!=b.val)
    {
        return a.val<b.val;
    }
    return a.ps>b.ps;
}
ll tree[4*maxn];
void update(int id,int l,int r,int ps,int val)
{
    if(l>ps || r<ps) return ;
    if(l==r)
    {
        tree[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,ps,val);
    update(id*2+1,mid+1,r,ps,val);
    tree[id*2]%=mod;
    tree[id*2+1]%=mod;
    tree[id]=tree[id*2]+tree[id*2+1];
    tree[id]%=mod;
}
ll query(int id,int l,int r,int i,int j)
{
    if(l>j || r<i) return 0;
    if(l>=i && r<=j)
    {
        return tree[id];
    }
    int mid=(l+r)/2;
    int p1=query(id*2,l,mid,i,j);
    int p2=query(id*2+1,mid+1,r,i,j);
    p1%=mod;
    p2%=mod;
    return p1+p2;
}
int save[maxn];
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        int n;
        sf("%d",&n);
        for(int i=1 ;i<=n ;i++ )
        {
            sf("%d",&ara[i].val);
            ara[i].ps=i;
        }
        sort(ara+1,ara+n+1,cmp);
        memset(tree,0,sizeof tree);
        for(int i=1 ;i<=n ;i++ )
        {
            data temp=ara[i];
            ll q=query(1,1,n,1,temp.ps);
//            cout << temp.val << ' ' << temp.ps << endl;
            q%=mod;
            update(1,1,n,temp.ps,q+1);
        }
        pf("Case %d: %lld\n",qq,tree[1]%mod);
    }
    return 0;
}
/*
2
5
1 2 1000 1000 1001
*/
