/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200000+7
#define B 450
int ara[maxn],cnt[2000000];
long long int ans=0;
struct node
{
	int l,r,id;
}Q[maxn];
bool cmp(node p,node q)
{
	int bp=p.l/B,bq=q.l/B;
	if(bp!=bq)
	{
		return bp<bq;
	}
	if(bp&1)
	{
		return p.r<q.r;
	}
	else
	{
		return p.r>q.r;
	}
}
inline void add(int ps)
{
	ans-=(1LL*cnt[ara[ps]]*cnt[ara[ps]]*ara[ps]);
	cnt[ara[ps]]++;
	ans+=(1LL*cnt[ara[ps]]*cnt[ara[ps]]*ara[ps]);
}
inline void rmv(int ps)
{
	ans-=(1LL*cnt[ara[ps]]*cnt[ara[ps]]*ara[ps]);
	cnt[ara[ps]]--;
	ans+=(1LL*cnt[ara[ps]]*cnt[ara[ps]]*ara[ps]);
}
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++)
    {
    	scanf("%lld",&ara[i]);
    	/*cin >> ara[i];*/
    }
    for(int i=0;i<t;i++)
    {
    	scanf("%d %d",&Q[i].l,&Q[i].r);
    	/*cin >> Q[i].l >> Q[i].r ;*/
    	Q[i].l--,Q[i].r--;
    	Q[i].id=i;
    }
    sort(Q,Q+t,cmp);
    int curl=0,curr=0;
    ll ansarray[t+7];
    /*cout << "YES" << endl;*/
    for(int i=0;i<t;i++)
    {
    	int L=Q[i].l,R=Q[i].r;
    	while(curl<L)
    	{
    		rmv(curl);
    		curl++;
    	}
    	while(curl>L)
    	{
    		add(curl-1);
    		curl--;
    	}
    	while(curr<=R)
    	{
    		add(curr);
    		curr++;
    	}
    	while(curr>R+1)
    	{
    		rmv(curr-1);
    		curr--;
    	}
    	/*cout << curl << " " << curr << endl;*/
    	ansarray[Q[i].id]=ans;
    }
    for(int i=0;i<t;i++)
    {
    	printf("%lld\n",ansarray[i]);
    	/*cout << ansarray[i] << endl;*/
    }
    return 0;
}