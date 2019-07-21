#include<bit/stdc++.h>
using namespace std;
vector<int>tree(4*100000+7),lazy(4*100000+7),vt(100000+7);
void bulid(int id,int l,int r)
{
    if(l==r)
    {
        tree[id]=vt[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id]=tree[id*2]+tree[id*2+1];
}
int main()
{
    ios_base::sync_with_stdio(0);

    return 0;
}
