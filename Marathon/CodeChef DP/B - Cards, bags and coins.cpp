/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,m;
ll dp[100007][3][107];
int ara[100007];
ll rec(int ps,int flag,int sum)
{
//	cout << sum << endl;
	if(ps>=n)
	{
		if(sum%m==0)
		{
			return 1;
		}
		return 0;
	}
	ll &ret=dp[ps][flag][sum];
	if(ret!=-1) return ret;
	ret=rec(ps+1,1,(sum+ara[ps])%m);
	ret%=1000000009;
	ret+=rec(ps+1,0,sum%m);
	ret%=1000000009;
	return ret;
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
    	int q;
    	scanf("%d %d",&n,&q);
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&ara[i]);
    	}
    	while(q--)
    	{
//    	    cout << "####" << endl;
    		scanf("%d",&m);
    		memset(dp,-1,sizeof dp);
    		ll ans=rec(0,0,0);
    		printf("%d\n", ans%1000000009);
    	}
    }
    return 0;
}
