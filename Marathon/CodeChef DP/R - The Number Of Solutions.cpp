/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll bigmod(ll a,ll b,ll m)
{
    /// a^b%m
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(a*ans)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
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
    	int n;
    	cin >> n;
    	int ara[n+7];
    	for(int i=1;i<=n;i++)
    	{
    		cin >> ara[i];
    	}
    	for(int i=1;i<=n;i++)
    		cout << ara[i] << " ";
    	cout << endl;
    	ll sum[107],dp[n+7];
    	ll ans=0;
    	for(int diff=1;diff<=1;diff++)
    	{
    		memset(sum,0,sizeof sum);
    		memset(dp,0,sizeof dp);
    		ll cur=0;
    		for(int i=1;i<=n;i++)
    		{
    			if( (ara[i]-diff) >= 0 and (ara[i]-diff) <= 100 )
    			{
    				/*cout << "difference " << diff << " " << ara[i]-diff << " " << i << endl;*/
    				dp[i]=dp[ara[i]-diff]+1;
    				/*cout << dp[i] << " ok " << endl;*/
    				sum[ara[i]]+=dp[i];
    				cur+=dp[i];
    				cur%=mod;
    				sum[i]%=mod;
    			}
    		}
/*    		cout << dp[1] << " " << dp[2] << " " << dp[3] << endl; 
    		cout << diff << " diff er jonno " << cur << endl;*/
    		if(cur)
			{
				ans+=cur;
	    		ans-=n;
	    		ans%=mod;
	    		/*cout << "ans " << ans << " diff " << diff  << " cur " << cur << endl;*/
			}
    	}
    	cout << ans << endl;
    	cout << "####" << endl;
    	for(int diff=-10;diff<0;diff++)
    	{
    		memset(sum,0,sizeof sum);
    		memset(dp,0,sizeof dp);
    		ll cur=0;
    		for(int i=1;i<=n;i++)
    		{
    			int f=0;
    			if( (ara[i]+diff) >= 0 and (ara[i]+diff) <= 100 )
    			{
    				cout << "difference " << diff << " " << ara[i]+diff << " " << i << endl;
    				f=1;
    				dp[i]=dp[ara[i]+diff]+1;
    				sum[ara[i]]+=dp[i];
    				cur+=dp[i];
    				cur%=mod;
    				sum[i]%=mod;
    			}
    		}
    		cout << diff << " diff er jonno " << cur << endl;
    		if(cur)
			{
				ans+=cur;
	    		ans-=n;
	    		ans%=mod;
	    		/*cout << "ans " << ans << " diff " << diff  << " cur " << cur << endl;*/
			}
    	}
    	cout << " ans " << ans << endl;
    	ans+=n;
    	cout << bigmod(2,n,mod) << " big " << endl;
    	ans=bigmod(2,n,mod)-1-ans;
    	cout << ans << endl;
    }
    return 0;
}