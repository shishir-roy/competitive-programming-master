#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,pair<int,int> > x, pair<int,pair<int,int> > y)
{
	if(x.first==y.first)
	{
		int dx=abs(x.first-x.second.first);
		int dy=abs(y.first-y.second.first);
		if(dx==dy)
		{
			return x.first>y.first;
		}
		else return dx>dy;
	}
	else return x.first>y.first;
}
int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	vector< pair<int,pair<int,int> > >temp;
	for(int i=0;i<n;i++)
	{
		int p,a,b;
		scanf("%d %d %d",&p,&a,&b);
		temp.push_back({a,{b,p}});
	}
	sort(temp.begin(),temp.end(),cmp);
	for(int i=0;i<n;i++)
		cout << temp[i].first << endl;
	
	return 0;
}