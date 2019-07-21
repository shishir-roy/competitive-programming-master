#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
int main()
{
	int tc;
	sf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n;
		sf("%d",&n);
		int cnt=0;
		ll nu=0;
		int f=0;
		for(int i=0;i<n;i++)
		{
			int t;
			sf("%d",&t);
			if(t<0)
			{
				cnt++;
			}
			else f=1;
			if(t<0)t*=-1;
			nu+=t;
		}
		ll du=n-cnt;
		if(!f)
		{
			pf("Case %d: inf\n",qq);
		}
		else
		{
			ll g=__gcd(nu,du);
			pf("Case %d: %lld/%lld\n",qq,nu/g,du/g);
		}
	}
	return 0;
}
/*

*/
