#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int>vt;
	vt.push_back(1);
	for(int i=0;i<=32;i++)
	{
		vt.push_back(vt.back()*2);
	}
	int tc;
	cin >> tc;
	while(tc--)
	{
		long long int sum=0;
		long long int n;
		cin >> n;
		sum+=(n*(n+1)/2);
		for(int  i=0;i<vt.size();i++)
		{
			if(vt[i]<=n)
				sum-=(vt[i]*2);
		}
		cout << sum << '\n';
	}
	return 0;
}
