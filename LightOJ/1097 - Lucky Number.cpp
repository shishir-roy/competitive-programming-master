#include<bits/stdc++.h>
using namespace std;
#define mxn 1429531
int tree[4*mxn+7];
int lucky[100007];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=l&1;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
int query(int id,int l,int r,int ps)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(tree[id*2]>=ps) return query(id*2,l,mid,ps);
    else return query(id*2+1,mid+1,r,ps-tree[id*2]);
}
void updt(int id,int l,int r,int ps)
{
    if(l==r)
    {
        tree[id]=0;
        return;
    }
    int mid=(l+r)/2;
    if(tree[id*2]>=ps) updt(id*2,l,mid,ps);
    else updt(id*2+1,mid+1,r,ps-tree[id*2]);
    tree[id]=tree[id*2]+tree[id*2+1];
}
void init()
{
    build(1,1,mxn);
    lucky[1]=1;
    vector<int>vt,tt;
    for(int i=2; i<=100000; i++)
    {
        int q=query(1,1,mxn,i);
        lucky[i]=q;
        int j = (mxn / q) * q;
        for(; j>=q; j -= q )
        {
            updt(1,1,mxn,j);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    init();
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        cin >> n;
        cout << "Case " << qq << ": " << lucky[n] << '\n';
    }
    return 0;
}
