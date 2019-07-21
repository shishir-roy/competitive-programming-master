/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,x[20],y[20];
int same_slope[20][20];
inline bool co_linier(int i,int j,int k)
{
	return (x[j]-x[k]) * (y[i]-y[j]) - (x[i]-x[j]) * (y[j]-y[k]) == 0;
}
void go()
{
	memset(same_slope,0,sizeof same_slope);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(i!=j and co_linier(i,j,k) )
				{
					same_slope[i][j]|=(1<<k);
				}
			}
		}
	}
}
int dp[(1<<16)+7];
int rec(int mask)
{
	if(mask==(1<<n)-1)
	{
		return 0;
	}
	if (__builtin_popcount(mask) == (n - 1))
    	return dp[mask] = 1;
	int &ret=dp[mask];
	if(ret!=-1) return ret;
	ret=INT_MAX;
	int i=0;

	for (i = 0; ((mask >> i) & 1); ++i);

	for (int j = 0; j < n; ++j)
    	if ((i != j) && !((mask >> j) & 1))
      		ret = min(ret, rec(mask | same_slope[i][j]) + 1);
	return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	cin >> n;
    	for(int i=0;i<n;i++)
    	{
    		cin >> x[i] >> y[i];
    	}
    	go();
    	memset(dp,-1,sizeof dp);
    	int ans=rec(0);
    	cout << "Case " << qq << ": " << ans << endl;
    }
    return 0;
}