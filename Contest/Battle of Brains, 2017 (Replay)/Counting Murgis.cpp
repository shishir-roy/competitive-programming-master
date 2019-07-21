/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,k;
ll dp[30][30];
ll rec(int ps,int prev)
{
	if(ps>=k)
		return 1;
	ll &ret=dp[ps][prev];
	if(ret!=-1)
		return ret;
	ret=0;
	int i=prev+1;
	for(;i<n;i++)
	{
		ret+=rec(ps+1,i);
	}
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
    	cin >> n >> k;
    	memset(dp,-1,sizeof dp);
    	ll ans=rec(0,0);
    	cout << ans << endl;
    }
    return 0;
}