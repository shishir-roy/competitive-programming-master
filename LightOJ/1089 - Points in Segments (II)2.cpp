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
#define maxn 50007
int tree[10000000];
void updt(int id,int l,int r,int i,int j)
{
    if(l>j || r<i) return;
    if(l>=i && r<=j)
    {
        tree[id]++;
        return;
    }
    int mid=(l+r)/2;
    updt(id*2,l,mid,i,j);
    updt(id*2+1,mid+1,r,i,j);
}
int query(int id,int l,int r,int ps)
{
    if(l==r && l==ps) return tree[id];
    int mid=(l+r)/2;
    if(ps<=mid) return query(id*2,l,mid,ps)+tree[id];
    else return query(id*2+1,mid+1,r,ps)+tree[id];
}
int main()
{
    int tc;
	sf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,q;
		sf("%d %d",&n,&q);
		map<ll,int>mp;
		int hv=1;
		vector< pair<ll,ll> >seg;
		vector<ll>all;
		for(int i=0;i<n;i++)
		{
			ll x,y;
			sf("%lld %lld",&x,&y);
			seg.push_back({x,y});
			all.push_back(x);
			all.push_back(y);
		}
		vector<ll>points;
		for(int i=0;i<q;i++)
		{
			ll t;
			sf("%lld",&t);
			points.push_back(t);
			all.push_back(t);
		}
		sort(all.begin(),all.end());
		for(int i=0;i<all.size();i++)
		{
            if(mp.find(all[i])==mp.end())
            {
                mp[all[i]]=hv++;
            }
		}
		memset(tree,0,sizeof tree);
		for(int i=0;i<n;i++)
		{
            updt(1,1,hv,mp[seg[i].fs],mp[seg[i].sc]);
        }
        pf("Case %d:\n",qq);
        for(int i=0;i<q;i++)
        {
            pf("%d\n",query(1,1,hv,mp[points[i]]));
        }
	}
	return 0;
}
/*

*/
