#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int r=0,b=0;
	for(int i=0;i<n;i++)
	{
		if( (i&1) and str[i]!='r') r++;
		else if( (!(i&1)) and str[i]!='b') b++;
	}
	int mx=max(r,b);
	r=0,b=0;
	for(int i=0;i<n;i++)
	{
		if( (i&1) and str[i]!='b') r++;
		else if( (!(i&1)) and str[i]!='r') b++;
	}
	int x=max(r,b);
	cout << min(mx,x)  << '\n';
	return 0;
}
