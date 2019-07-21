/*
ID:shishir10
TASK:skidesign
LANG:C++11
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int n;
	vector<int>vt;
	fin >> n;
	for(int i=0;i<n;i++)
	{
		int t;
		fin >> t;
		vt.push_back(t);
	}
	sort(vt.begin(),vt.end());
	int mn=INT_MAX;
	for(int st=0;st<vt[n-1];st++)
	{
		int low=st;
		int hi=low+17;
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(vt[j]<low)
			{
				ans+=( (low-vt[j]) * (low-vt[j]) );
			}
			else if(vt[j]>hi)
			{
				ans+=( (vt[j]-hi) * (vt[j]-hi) );
			}
		}
		mn=min(mn,ans);
	}
//	cout << mn << endl;
	fout << mn << '\n';
	return 0;
}
