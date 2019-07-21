#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200007
int ara[maxn],cnt[1000007];
int block;
struct  data
{
	int l,r,idx;
	bool operator < (const data &a)const
	{
		if(l/block!=a.l/block)
		{
			return l/block < a.l/block;
		}
		return r < a.r;
	}
}Q[maxn];

int id[maxn];
inline void add(int ps)
{
	cnt[ara[ps]]++;
	if(cnt[ara[ps]]==1)
	{
		id[ara[ps]]=ps;
	}
}

inline void remove(int ps)
{
	cnt[ara[ps]]--;
	if(cnt[ara[ps]]==0)
	{
		id[ara[ps]]=-1;
	}
}


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&ara[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",Q[i].l,Q[i].r,Q[i].x);
		Q[i].idx=i;
	}
	sort(Q,Q+m);
	int curL=0,curR=0;
	add(0);
	for(int i=0;i<m;i++)
	{
		while(curL<Q.l) remove(curL++);
		while(culL>Q.l) add(--curL);
		
	}
	return 0;
}