#include<bits/stdc++.h>
using namespace std;
int lps[800];
void LPS(string str)
{
	memset(lps,0,sizeof lps);
	int j=0;
	lps[0]=0;
	int i=1;
	while(i<str.size())
	{
		if(str[j]==str[i])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else
		{
			if(j==0)
			{
				lps[i]=0;
				i++;
			}
			else
			{
				j=lps[j-1];
			}
		}
	}
}
in
int main()
{
	string str;
	cin >> str;
	LPS(str);
	for(int i=0;i<str.size();i++)
	{
		cout << lps[i] << " " ;
	}
	
	cout << '\n';
	return 0;
}
