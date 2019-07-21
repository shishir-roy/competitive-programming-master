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
#define maxn 1000007
struct data
{
    int val=0,ps=0;
};
bool cmp(data a,data b)
{
    if(a.val!=b.val)
    {
        return a.val<b.val;
    }
    return a.ps>b.ps;
}
data ara[maxn];
ll res[maxn];
int tree[maxn];
void shift(int id,int l,int r)
{
    if(l==r)
    {
        res[l]+=lazy[id];
    }
    else
    {
        lazy[id*2]=lazy[id];
        lazy[id*2+1]=lazy[id];
    }
    lazy[id]=0;
}
void updt(int id,int l,int r,int ps)
{
    if(l>ps || r<ps)
        return;
    if(l>=ps && r<=ps)
    {
        tree[id]=1;
        return;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    sf("%d",&n);
    for(int i=1 ;i<=n ;i++ )
    {
        sf("%d",&ara[i].val);
        ara[i].ps=i;
    }
    return 0;
}
/*

*/
