#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		unordered_map<int,int>mp;
		int st=1;
		int mx=0,i;
		for(i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			if(mp[t] && mp[t]>=st)
			{
				mx=max(mx,i-st);
				st=max(st,mp[t])+1;
			}
			mp[t]=i;
		}
		mx=max(mx,i-st);
		cout << mx << '\n';
	}
//	cout << '\n';
	return 0;
}

