#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>tree[4*100000+7];
vector<int>vt(100000);
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id].push_back(vt[l]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    merge(tree[id*2].begin(),tree[id*2].end(),tree[id*2+1].begin(),tree[id*2+1].end(),back_inserter(tree[id]));
}
int query(int id,int l,int r,int i,int j,int val)
{
    if(r<i || l>j) return 0;
    if(l>=i and r<=j)
        return upper_bound(tree[id].begin(),tree[id].end(),val)-tree[id].begin() ;
    int mid=(l+r)/2;
    return query(id*2,l,mid,i,j,val) + query(id*2+1,mid+1,r,i,j,val);
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> vt[i];
    build(1,1,n);
    for(int q=0; q<m; q++)
    {
        int i,j,k;
        cin >> i >> j >> k;
        ll l=-1000000007,r=1000000007;
        int t=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            int tt=query(1,1,n,i,j,mid);
            if(tt>=k)
            {
                t=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << t << endl;
    }
    return 0;
}

