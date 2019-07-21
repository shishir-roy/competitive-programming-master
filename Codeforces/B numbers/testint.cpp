#include<bits/stdc++.h>
using namespace std;
int tree[507][507*4],ara[507][507];
 
void build(int id,int l,int r,int row)
{
    if(l==r)
    {
        tree[row][id]=ara[row][l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid,row);
    build(id*2+1,mid+1,r,row);
    tree[row][id]=max(tree[row][id*2],tree[row][id*2+1]);
}
 
int query(int id,int l,int r,int row,int ql,int qr)
{
    if(r<ql || l>qr) return INT_MIN;
    if(l>=ql and r<=qr) return tree[row][id];
    int mid=(l+r)/2;
    return max(query(id*2,l,mid,row,ql,qr),query(id*2+1,mid+1,r,row,ql,qr));
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        printf("Case %d:\n",qq);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&ara[i][j]);
        for(int i=1;i<=n;i++) build(1,1,n,i);
        while(q--)
        {
            int p,q,s;
            scanf("%d %d %d",&p,&q,&s);
            int ans=INT_MIN;
            for(int i=p;i<=p+s-1;i++)
            {
                ans=max(ans,query(1,1,n,i,q,q+s-1));
            }
            printf("%d\n",ans );
        }
    }
    return 0;
}