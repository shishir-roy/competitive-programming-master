#include<bits/stdc++.h>
using namespace std;
queue<char>vt;
bool func(string str,int u,int v)
{
	int flag[29]={};
	int cnt=0;
	for(int i=u;i<=v;i++)
	{
		if(str[i]!='?')
		{
			flag[str[i]-'A']++;
		}
		else cnt++;
	}
	int c=0;
	while(!vt.empty())
		vt.pop();
	for(int i=0;i<26;i++)
	{
		if(flag[i]==0)
		{
			vt.push(i+'A');
			c++;
		}
	}
	//cout << "cnt " << cnt << " c " << c << endl;
	if(c==cnt)
	{	
		return 1;
	}
	else 
	{
		return 0;
	}
}
int main()
{
	string str;
	cin >> str;
	//cout << "*** " << endl;
	int ans=0;
	if(str.size()<26)
	{
		cout << -1 << '\n';
	}
	else 
	{
		int x=0,y=25;
		for(;y<str.size();x++,y++)
		{
		//	cout << "loop run " << endl;
			if(func(str,x,y))
			{
				ans=1;
				while(x<=y)
				{
					if(str[x]=='?')
					{
			//			cout << vt.front() << endl;
						str[x]=vt.front();
						vt.pop();
					}
					x++;
				}
				break;
			}
		}
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='?')
			{
				str[i]='A';
			}
		}
		//cout << "ei " << endl;
		if(ans)
			cout << str << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}							
