/*input

*/
// d-query problem ac solution
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 2000000+7
ll block;
struct  data
{
	ll l,r,idx;
	bool operator < (const data &a) const
	{
		if(l/block!=a.l/block) return l/block < a.l/block;
		return r < a.r;
	}
}Q[maxn];
ll n,m;
// the size of the cnt should be equal to largest element of the array
ll ara[maxn],ans[maxn],counti=0;
int cnt[maxn];
inline void add(ll ps)
{
    if(ara[ps]>n) return;
	cnt[ara[ps]]++;
	if(cnt[ara[ps]]==ara[ps])
	{
		counti++;
	}
	else if(cnt[ara[ps]] > ara[ps])
	{
		counti--;
	}
}


inline void remove(ll ps)
{
    if(ara[ps]>n) return;
	cnt[ara[ps]]--;
	if(cnt[ara[ps]]==ara[ps]-1)
		counti--;
	if(cnt[ara[ps]]==ara[ps])
	{
		counti++;
	}
}


int main()
{
    scanf("%lld %lld",&n, &m);
    block=sqrt(n);
    for(ll i=1;i<=n;i++)
    {
    	scanf("%lld", &ara[i]);
    	cnt[ara[i]]=0;
    }
    for(ll i=0;i<m;i++)
    {
    	scanf("%lld %lld",&Q[i].l, &Q[i].r);
    	Q[i].idx=i;
    }
    ll curL=1,curR=1;
    cnt[ara[1]]++;
    if(cnt[ara[1]]==ara[1])counti++;
    sort(Q,Q+m);
    for(ll i=0;i<m;i++)
    {
    	while(curL < Q[i].l)
    		remove(curL++);
    	while(curL > Q[i].l)
    		add(--curL);
    	while(curR < Q[i].r)
    		add(++curR);
    	while(curR > Q[i].r)
    		remove(curR--);
    	ans[Q[i].idx]=counti;
    }
    for(ll i=0;i<m;i++)
    	printf("%lld\n",ans[i]);
    return 0;
}
