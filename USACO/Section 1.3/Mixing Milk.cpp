/*
ID:shishir10
LANG:C++11
TASK:milk
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	long long int total;
	cin >> total;
	int n;
	cin >> n;
	vector< pair<int,int> >vt;
	for(int i=0;i<n;i++)
	{
		int pu,am;
		cin >> pu >> am;
		vt.push_back(make_pair(pu,am));
	}
	sort(vt.begin(),vt.end());;
	long long int cost=0LL;
	for(int i=0;i<vt.size() and total>0;i++)
	{
		long long int  temp=vt[i].second;
		if(total>=temp)
		{
			cost+=(vt[i].first*temp);
			total-=temp;
		}
		else
		{
			cost+=(vt[i].first*total );
			total=0;
		}
	}
	cout << cost << '\n';
	//cout << total << endl;
	return 0;
}	
