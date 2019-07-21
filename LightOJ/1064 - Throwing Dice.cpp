/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,x;
unsigned long long int dp[27][157];
unsigned long long int rec(int ps,int sum)
{
	if(ps>=n)
	{
		if(sum>=x) return 1;
		return 0;
	}
	unsigned long long int &ret=dp[ps][sum];
	if(ret!=-1) return ret;
	ret=0ULL;
	for(int i=1;i<=6;i++)
	{
		ret+=rec(ps+1,sum+i);
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
    for(int qq=1;qq<=tc;qq++)
    {
    	cin >> n >> x;
    	memset(dp,-1,sizeof dp);
    	unsigned long long int a=rec(0,0), b=1;
    	for(unsigned long long int i=1;i<=n;i++)
    	{
    		b*=6;
    	}
    	unsigned long long int c=__gcd(a,b);
    	a/=c;
    	b/=c;
    	if(a%b==0)
    	{
    		cout << "Case " << qq << ": " << a/b << endl;
    	}
    	else
    	{
    		cout << "Case " << qq << ": " << a << "/" << b << endl;
    	}
    }
    return 0;
}