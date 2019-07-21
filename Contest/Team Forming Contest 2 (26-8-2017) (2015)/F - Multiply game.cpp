/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxn 50000+7
ll tree[5*maxn];
ll ara[maxn];
void build(int id,int l,int r)
{
	if(l==r)
	{
		tree[id]=ara[l];
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tree[id]=(tree[id*2]*tree[id*2+1])%mod;
}
void updt(int id,int l,int r,int ps,int u)
{
	if(l==r)
	{
		tree[id]=u;
		return;
	}
	int mid=(l+r)/2;
	if(ps<=mid) updt(id*2,l,mid,ps,u);
	else updt(id*2+1,mid+1,r,ps,u);
	tree[id]=(tree[id*2]*tree[id*2+1])%mod;
}
ll query(int id,int l,int r,int ql,int qr)
{
	if(r<ql || l>qr) return 1;
	if(l>=ql and r<=qr) return tree[id];
	int mid=(l+r)/2;
	return (query(id*2,l,mid,ql,qr)*query(id*2+1,mid+1,r,ql,qr) )%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
    	int n;
    	cin >> n;
    	for(int i=1;i<=n;i++)
    	{
    		cin >> ara[i];
    	}
    	build(1,1,n);
    	int q;
    	cin >> q;
    	while(q--)
    	{
    		int a,b,c;
    		cin >> a >> b >> c;
    		if(a==1)
    		{
    			updt(1,1,n,b,c%mod);
    		}
    		else
    		{
    			cout << query(1,1,n,b,c) << endl;
    		}
    	}
    }
    return 0;
}