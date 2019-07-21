#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    long long int sum=0,mxpre=0,mxsuf=0,mxsb=0;
};
node tree[4*50000];
vector<int>vt( 50000+7);
long long int tt=1;
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id].sum=tree[id].mxpre=tree[id].mxsuf=tree[id].mxsb=vt[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].sum=tree[id*2].sum + tree[id*2+1].sum;
    tree[id].mxpre=max(tree[id*2].mxpre,tree[id*2].sum+tree[id*2+1].mxpre);
    tree[id].mxsuf=max(tree[id*2+1].mxsuf,tree[id*2+1].sum+tree[id*2].mxsuf);
    tree[id].mxsb=max(tree[id*2].mxsb,max(tree[id*2+1].mxsb,tree[id*2].mxsuf+tree[id*2+1].mxpre));
}
void updt(int id,int l,int r,int pos,int val)
{
    if(pos<l || r<pos)
    {
        return ;
    }
    if(l==r and l==pos)
    {
        tree[id].sum=tree[id].mxpre=tree[id].mxsuf=tree[id].mxsb=val;
        return ;
    }
    int mid=(l+r)/2;
    updt(id*2,l,mid,pos,val);
    updt(id*2+1,mid+1,r,pos,val);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].mxpre=max(tree[id*2].mxpre,tree[id*2].sum+tree[id*2+1].mxpre);
    tree[id].mxsuf=max(tree[id*2+1].mxsuf,tree[id*2+1].sum+tree[id*2].mxsuf);
    tree[id].mxsb=max(tree[id*2].mxsb,max(tree[id*2+1].mxsb,tree[id*2].mxsuf+tree[id*2+1].mxpre));
}
node query(int id,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
    {
        node a;
        a.sum=a.mxpre=a.mxsuf=a.mxsb=INT_MIN;
        return a;
    }
    if(l>=ql && r<=qr)
    {
        return tree[id];
    }
    int mid=(l+r)/2;
    node left,right,ans;
    left=query(id*2,l,mid,ql,qr);
    right=query(id*2+1,mid+1,r,ql,qr);
    ans.sum=left.sum+right.sum;
    ans.mxpre=max(left.mxpre,left.sum+right.mxpre);
    ans.mxsuf=max(right.mxsuf,right.sum+left.mxsuf);
    ans.mxsb=max(left.mxsb,max(right.mxsb,left.mxsuf+right.mxpre));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> vt[i];
    build(1,1,n);
    int m;
    cin >> m;
    while(m--)
    {
        int t,ql,qr;
        cin >> t >> ql >> qr;
        if(t==0)
        {
            updt(1,1,n,ql,qr);
        }
        else
        {
            cout << query(1,1,n,ql,qr).mxsb << endl;
        }
    }
    return 0;
}