#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second
int main()
{
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		int mx,ans=INT_MIN;
		cin >> mx;
		n--;
		while(n--)
		{
			int t;
			cin >> t;
			ans=max(ans,mx-t);
			mx=max(mx,t);
		cout << ans << '\n';	
	}
	return 0;
}
