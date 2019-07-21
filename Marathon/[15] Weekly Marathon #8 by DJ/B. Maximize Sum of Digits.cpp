/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>vt;
int sum(ll t)
{
	int ans=0;
	while(t>0)
	{
		vt.push_back(t%10);
		ans+=(t%10);
		t/=10;
	}
	reverse(vt.begin(),vt.end());
	return ans;
}
void solve(ll x)
{
	int a=sum(x);
	vector<int>res;
	int sum=0,p=0;
	for(int i=0;i<vt.size();i++)
	{
		if(vt[i]==0) continue;
		int t=p+vt[i]-1+9*(vt.size()-i-1);
		p=p+vt[i];
		if(t>=sum)
		{
			sum=t;
			res.clear();
			for(int j=0;j<i;j++) res.push_back(vt[j]);
			res.push_back(vt[i]-1);
			for(int j=i+1;j<vt.size();j++) res.push_back(9);
		}
	}
	if(sum<=a)
	{
		res=vt;
	}
	int i=0;
	for(;i<res.size();i++)
	{
		if(res[i]!=0) break;
	}
	for(;i<res.size();i++) 
	{
		cout << res[i];
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x;
    cin >> x;
    solve(x);
    return 0;
}