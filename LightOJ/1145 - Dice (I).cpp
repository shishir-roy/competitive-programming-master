#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 100000007
ll dp[15007],pre[15007]; 
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,k,sum;
		scanf("%d %d %d",&n,&k,&sum);
		memset(dp,0,sizeof dp);
		memset(pre,0,sizeof pre);
		for(int pos=1;pos<=n;pos++)
		{
			for(int s=1;s<=sum;s++)
			{
				pre[s]=(pre[s-1]+dp[s])%mod;
			}
			for(int s=1;s<=sum;s++)
			{
				if(pos==1)
				{
					if(s<=k)
						dp[s]=1;
					else dp[s]=0;
				}
				else
				{
					int l=max(s-k,1);
					int r=s-1;
					dp[s]=(pre[r]-pre[l-1]+mod)%mod;
				}
			}
		}
		printf("Case %d: %lld\n", qq,dp[sum]%mod);
	}
	return 0;
}