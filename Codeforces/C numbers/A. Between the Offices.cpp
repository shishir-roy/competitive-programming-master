#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int s=0,f=0;
	for(int i=1;i<str.size();i++)
	{
		if(str[i]=='F' and str[i-1]=='S') f++;
		if(str[i]=='S' and str[i-1]=='F')s++;
	}
	if(s<f)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
