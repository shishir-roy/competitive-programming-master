/*
ID:shishir10
LANG:C++
TASK:dualpal
*/
#include<bits/stdc++.h>
using namespace std;
string con(int num,int b)
{
	char ara[]={'0','1','2','3','4','5','6','7','8','9','A','B'};
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
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	cin >> n >> s ;
	int cnt=0;
	while(1)
	{
		++s;
		int c=0;
		for(int i=2;i<=10;i++)
		{
			string str=con(s,i);
			string t=str;
			reverse(str.begin(),str.end());
			if(str==t)
			{
				c++;
			}
			if(c>=2)
			{
				cnt++;
				cout << s << '\n';
				break;
			}
		}
		if(cnt==n)
			break;
	}
	return 0;
}
