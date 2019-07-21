#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		set<int>st;
		int t;
		while(n--)
		{
			cin >> t;
			st.insert(t);
		}
		cout << st.size() << '\n';
	}
	return 0;
}
