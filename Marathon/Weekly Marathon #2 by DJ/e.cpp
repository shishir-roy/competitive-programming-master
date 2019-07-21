#include<bits/stdc++.h>
using namespace std;
int small(int ara[],int n,int sum)
{
	map<int,int>mp;
	int mx=n+7;
	for(int i=0;i<n;i++)
	{
		int cur=cur+ara[i];
		if(cur==sum)
		{
			mx=min(mx,i+1);
		}
		if(mp.find(cur-sum)!=mp.end())
		{
			mx=min(mx,i-mp[cur-sum]);
		}
		mp[cur]=i;
	}
	return mx;
}
int smallv2(int ara[],int n,int sum)
{
	int cur=0,st=0,mx=INT_MAX;
	for(int i=0;i<=n;i++)
	{
		while(cur>=sum and st<i)
		{
			mx=min(mx,i-st);
//			cout <<cur << " " << st << " " << i << endl;
			cur-=ara[st];
			st++;
		}
		cur+=ara[i];
	}
	return mx;
}
int main()
{
	//ios_base::sync_with_stdio(0);
	int n,sum;
	while(cin >> n >> sum)
	{
		int ara[n+2];
		for(int i=0;i<n;i++)
		{
			cin >> ara[i];
		}
		int ans=smallv2(ara,n,sum);
		if(ans==INT_MAX) cout << "0" << '\n';
		else
            cout << ans << '\n';
	}
	return 0;
}
