/*
ID:shishir10
LANG:C++
TASK:palsquare
*/
#include<bits/stdc++.h>
using namespace std;
int b;
string con(int num)
{
	char ara[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L'};
	string str;
	while(num>0)
	{
		str+=ara[num%b];
		num/=b;
	}
	return str;
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	cin >> b;
	for(int i=1;i<=300;i++)
	{
		string t=con(i*i);
		string tt=t;
		reverse(t.begin(),t.end());
		if(t==tt)
		{
			string a=con(i);
			reverse(a.begin(),a.end());
			cout << a << " " << t << '\n';
		}
	}
	return 0;
}
