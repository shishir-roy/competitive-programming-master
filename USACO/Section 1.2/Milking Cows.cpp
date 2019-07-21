/*
ID:shishir10
LANG:C++
TASK:milk2

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n;
	cin >> n;
	vector< pair<int,int> > vt;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		vt.push_back(make_pair(a,b));
	}
	sort(vt.begin(),vt.end());
	int u=vt[0].first;
	int v=vt[0].second;
	int mc=v-u,nmc=0,i;
	for(i=0;i<n-1;i++)
	{	
		if(vt[i+1].first>v)
		{
			mc=max(mc,v-u);
			nmc=max(nmc,vt[i+1].first-v);
			u=vt[i+1].first;
//			v=vt[i+1].second;
		}
		v=max(v,vt[i+1].second);
	}
	mc=max(mc,vt[i].second-u);
	cout << mc << " " << nmc << '\n';
	return 0;
}
