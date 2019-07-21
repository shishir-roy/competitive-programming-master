/*
ID:shishir10
LANG:C++11
TASK:crypt1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n;
	cin >> n;
	vector<int>vt;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		vt.push_back(t);
	}
	sort(vt.begin(),vt.end());
	vector<int>three,two;
	unordered_map<int,int>mp,ff;
	for(int i=0;i<vt.size();i++)
	{
		for(int j=0;j<vt.size();j++)
		{
			for(int k=0;k<vt.size();k++)
			{
				int a=vt[i]*100+vt[j]*10+vt[k];
				three.push_back(a);
				mp[a]++;
				for(int l=0;l<vt.size();l++)
				{
					int b=vt[l]*1000+a;
					ff[b]++;
				}
			}
		}
	}
	for(int i=0;i<vt.size();i++)
	{
		for(int j=0;j<vt.size();j++)
		{
			int a=vt[i]*10+vt[j];
			two.push_back(a);
		}
	}
	sort(three.begin(),three.end());
	sort(two.begin(),two.end());
	int cnt=0;
	for(int i=0;i<three.size();i++)
	{
		for(int j=0;j<two.size();j++)
		{
			int a=three[i]*two[j];
			int b=three[i]*(two[j]%10);
			int c=three[i]*(two[j]/10);
			if(a>9999)
				break;
			if(ff.find(a)!= ff.end() and mp.find(b)!=mp.end() and mp.find(c)!=mp.end())
			{
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
