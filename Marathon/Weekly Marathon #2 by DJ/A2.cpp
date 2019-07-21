#include<bits/stdc++.h>
#define ll long long int
#define pair<ll,ll>
#define fs first
#define sc second
bool cmp(const  pair<ll,pair<ll,ll> & a,const pair<ll,pair<ll,ll> & b)
{
	return a.fs<b.fs;
}
int main()
{
	int n;
	while(cin>>n)
	{
		ll ara[n+7];
		vector< pair<ll,pair<ll,ll> > >add,sub;
		for(int i=0;i<n;i++)
		{
			cin >> ara[i];
		}
		sort(ara,ara+n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{	
				add.push_back( { ara[i]+ara[j] , {ara[i],ara[j]} });
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				if(ara[i]-ara[j]<0)break;
				sub.push_back( { ara[i]-ara[j] , {ara[i],ara[j]} });
			}
		}
		sort(sub.begin(),sub.end(),cmp);
		for(int i=0;i<add.size();i++)
		{
			if(binary_search(sub.begin(),sun.end(),add[i].fs) )
			{
				auto l=lower_bound(sub.begin(),sub.end(),add[i].fs)-sub.begin();
				auto h=upper_bound(sub.begin(),sub.end(),add[i].fs)-sub.begin();
			}
		}
	}
	return 0;
}
