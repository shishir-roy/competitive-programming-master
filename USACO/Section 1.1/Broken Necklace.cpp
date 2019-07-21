/*

ID:shishir10
LANG:C++
TASK:beads

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	str+=str;
	int mx=0;
	int f=1;
	for(int i=0;i<n;i++)
	{
		if(str[i]!='w')
			f=0;
	}
	if(f) 
	{
		cout << n << endl;
		return 0;
	}
//	cout << str[5] << " " << str[6] << endl;
	for(int i=0;i<str.size() and i<n;i++)
	{
		if(str[i]=='b')
		{
		
			int rpaisi=0;
			int j;
			for(j=i+1;j<str.size();j++)
			{
				if(j==n+i){
				//	j--;
					break;
				}
				if(str[j]=='r')
				{
					rpaisi=1;
				}
				if(rpaisi==1 and str[j]=='b')
				{
					break;
				}
			}
			int cur=i;
			while(1&cur)
			{
				if(str[cur-1]!='w')
				{
					break;
				}
				cur--;
			}
/*
			if(mx<j-cur+1)
			{
				cout << "b theke print hocce " << endl;
				cout << j << " "  << cur << endl;
				cout << j-cur+1 << endl << endl;
			}
*/
			mx=max(mx,j-cur);
		}
	
		else if(str[i]=='r')
		{
		
			int bpaisi=0;
			int j;
			for(j=i+1;j<str.size();j++)
			{
	
				if(j==n+i){
				//	j--;
					break;
				}
				if(str[j]=='b')
				{
					bpaisi=1;
				}
				if(bpaisi==1 and str[j]=='r')
				{
					break;
				}
			}
			int cur=i;
			while(1*cur)
			{
				if(str[cur-1]!='w')
				{
					break;
				}
				cur--;
			}
/*			if(mx<j-cur+1)
			{
				cout << "r theke print hocce " << endl;
				cout << j << " "  << cur << endl;
				cout << j-cur+1 << endl << endl;
			}
*/
			mx=max(mx,j-cur);
		}
	}
	cout << mx << endl;
	return 0;
}
