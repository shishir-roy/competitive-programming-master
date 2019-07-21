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
	sf(""%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,q;
		sf("%d %d",&n,&q);
		unorderd_map<ll,int>mp;
		hv=1;
		vector<pii>seg;
		for(int i=0;i<n;i++)
		{
			int x,y;
			sf("%d %d",&x,&y);
			if(mp.find(x)==mp.end())
			{
				mp[x]=hv++;
			}
			if(mp.find(y)==mp.end())
			{
				mp[y]=hv++;
			}
			seg.push_back({mp[x],mp[y]});
		}
		vector<int>points;
		for(int i=0;i<q;i++)
		{
			int t;
			sf("%d",&t);
			if(mp.find(t)==mp.begin())
			{
				mp[t]=hv++;
			}
			points.push_back(mp[t]);
		}
	`}
	return 0;
}

		}
	return 0;
}
/*

*/
