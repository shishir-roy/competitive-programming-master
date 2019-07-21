#include<bits/stdc++.h>
using namespace std;
vector<long long int>vt(50000+8);
class node
{
    public:
        long long int sum=0,left=0,right=0,best=0;
};
node tree[4*50000];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id].sum=tree[id].left=tree[id].right=tree[id].best=vt[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].left=max(tree[id*2].left, tree[id*2].sum+tree[id*2+1].left);
    tree[id].right=max(tree[id*2+1].right,tree[id*2+1].sum+tree[id*2].right);
    tree[id].best=max(tree[id*2].best,max(tree[id*2+1].best,tree[id*2].right+tree[id*2+1].left) );
}
node query(int id,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql)
    {
        node a;
        a.sum=a.left=a.right=a.best=INT_MIN;
        return a;
    }
    if(l>=ql && r<=qr)
        return tree[id];
    int mid=(l+r)/2;
    node ans,ll,rr;
    ll=query(id*2,l,mid,ql,qr);
    rr=query(id*2+1,mid+1,r,ql,qr);
    ans.sum=ll.sum+rr.sum;
    ans.left=max(ll.left,ll.sum+rr.left);
    ans.right=max(rr.right,rr.sum+ll.right);
    ans.best=max(ll.best,max(rr.best,ll.right+rr.left) );
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
        int ql,qr;
        cin >> ql >> qr;
        long long int ans=query(1,1,n,ql,qr).best;
        if(ql==qr)
            ans=vt[ql];
        cout << ans << '\n';
    }
    return 0;
}
