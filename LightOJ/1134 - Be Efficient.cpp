#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,m;
		scanf("%d %d",&n,&m);

		ll temp[m+7];
		memset(temp,0,sizeof temp);
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			sum+=t;
			sum%=m;
			temp[sum]++;
		}

		ll ans=temp[0];
		for(int i=0;i<m;i++)
		{
			ans+=(temp[i]*(temp[i]-1)/2);
		}
		printf("Case %d: %lld\n", qq,ans);
	}
	return 0;
}