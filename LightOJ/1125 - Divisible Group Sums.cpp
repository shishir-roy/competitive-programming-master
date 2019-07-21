/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,q,d,m,ara[207];
  long long int dp[207][17][27];
  long long int rec(int ps,int cnt,ll sum)
{
	if(ps>=n)
	{
		if(cnt==m && ( (sum%d)+d )%d==0) return 1ll;
		return 0ll;
	}
	  long long int &ret=dp[ps][cnt][sum];
	if(ret!=-1) return ret;
	ret=0ll;
	ret+=rec(ps+1,cnt+1,( (sum+ara[ps])%d +d )%d );
	ret+=rec(ps+1,cnt,sum%d );
	return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	cin >> n >> q;
    	for(int i=0;i<n;i++)
    		cin >> ara[i];
    	cout << "Case " << qq << ":" << endl;
    	while(q--)
    	{
    		cin >> d >> m;

    		memset(dp,-1,sizeof dp);
    		cout << rec(0,0,0) << endl;
    	}
    }
    return 0;
}