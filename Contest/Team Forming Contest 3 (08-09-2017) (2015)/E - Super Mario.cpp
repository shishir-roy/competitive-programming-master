/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>tree[4*maxn];
int ara[maxn];
void bulid(int id,int l,int r)
{
	if(l==r)
	{
		tree[id].push_back(ara[l]);
		return ;
	}
	int mid=(l+r)/2;
	bulid(id*2,l,mid);
	bulid(id*2+1,mid+1,r);
	merge(tree[id*2].begin(),tree[id*2].end(), tree[id*2+1].begin(),tree[id*2+1].end(), back_inserter(tree[id]) );
}
int query(int id,int l,int r,int ql,int qr,int val)
{
    if(r<ql || l>qr) return 0;
    if(l>=ql and r<=qr)
    {
        /*cout << id << " " << l << " " << r <<  endl;
        cout << (upper_bound(tree[id].begin(),tree[id].end(),val)- tree[id].begin() ) << endl;*/
        return (upper_bound(tree[id].begin(),tree[id].end(),val)- tree[id].begin());
    }
    int mid=(l+r)/2;
    int t1=query(id*2,l,mid,ql,qr,val);
    int t2=query(id*2+1,mid+1,r,ql,qr,val);
    return t1+t2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    int qq=1;
    while(tc--)
    {
        for(int i=0;i<4*maxn;i++)
        {
            tree[i].clear();
        }
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> ara[i];
        bulid(1,0,n-1);
        /*cout << upper_bound(tree[6].begin(),tree[6].end(),6)-tree[6].begin() << endl;*/
        cout << "Case " << qq++ << ":" << endl;
        while(m--)
        {
            int l,r,h;
            cin >> l >> r >> h;
            cout << query(1,0,n-1,l,r,h) << endl;
        }
    }
    return 0;
}
