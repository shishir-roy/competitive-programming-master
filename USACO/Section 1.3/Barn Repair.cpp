/*
ID:shishir10
LANG:C++
TASK:barn1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("barn1.in","r",stdin);
 	freopen("barn1.out","w",stdout);
	ios_base::sync_with_stdio(0);
	int m,s,c;
	cin >> 	m >> s >> c;
	int flag[200+7];
	int mn=9000,mx=-1;
	memset(flag,-1,sizeof flag);
	while(c--)
	{
		int t;
		cin >>  t;
		flag[t]=1;
		mn=min(mn,t);
		mx=max(mx,t);
	}
	int cnt=1;
	int seg[200+7];
	for(int i=0;i<200+7;i++)
	{
		seg[i]=1;
	}
	while(cnt<m)
	{
		int x=0,mxx=-1,u,v;
		for(int i=mn;i<=mx;i++)
		{
			if(seg[i]==1 and flag[i]==-1 and x==0)
			{
				x=i;
			}
			else if(seg[i]==0 or flag[i]==1)
			{
				if(i-x>mxx and x!=0)
				{
					mxx=max(mxx,i-x);
					u=x;
					v=i;
				}
				x=0;
			}
		
		}
		for(int i=u;i<v;i++)
		{
			seg[i]=0;
		}
		cnt++;
	}
	int ans=0;
	for(int i=mn;i<=mx;i++)
	{
		if(seg[i]==1)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}	
