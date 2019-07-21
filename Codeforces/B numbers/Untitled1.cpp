#include<bits/stdc++.h>
using namespace std;
#define DB printf("*****\n")
#define sf scanf
#define pf printf
#define ll long long int
#define pii pair<int,int>
#define inf 2147483647
#define maxn 100004
int ara[maxn];
int tree[3*maxn];
void init(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=ara[l];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    init(left,l,mid);
    init(right,mid+1,r);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int l,int r,int i,int j)
{
    if(l>=i and r<=j) return tree[node];
    if(j<l or i>r) return inf;
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    int p1=query(left,l,mid,i,j);
    int p2=query(right,mid+1,r,i,j);
    return min(p1,p2);
}
void update(int node,int l,int r,int i,int value)
{
    if(l>i or r<i) return;
    if(l==r)
    {
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(l+r)/2;
    update(left,l,mid,i,value);
    update(right,mid+1,r,i,value);
    tree[node]=min(tree[left],tree[right]);
}
int main()
{
    int tc;
    sf("%d",&tc);
    int n,q;
    for (int qq=1;qq<=tc ;qq++ )
    {
        sf("%d %d",&n,&q);
        for (int i=1;i<=n ;i++ )
        {
            sf("%d",&ara[i]);
        }
        init(1,1,n);
        pf("Case %d:\n",qq);
        int i,j;
        while(q--)
        {
            sf("%d %d",&i,&j);
            pf("%d\n",query(1,1,n,i,j));
        }
    }
    return 0;
}
/*
78 1 22 12 3

*/
