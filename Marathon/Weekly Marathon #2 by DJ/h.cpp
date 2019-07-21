#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		char ch=getchar();
		//cout << ch << endl;
		int ara[n+8];
		int index[n+8];
		for(int i=0;i<n;i++)
		{
			cin >> ara[i];
			index[ara[i]]=i;
		}
		int f=1;
		//cout << index[4] << ara[3] << endl;
		for(int i=0;i<n and f;i++)
		{
			for(int j=i+1;j<n and f;j++)
			{
				int k=ara[j]+ara[j]-ara[i];
				//cout << i << endl;
				if(k>=0 and k<n and index[k]>j)
				{
					f=0;
					cout << "no" << '\n';
				}
			}
		}
		if(f)
		{
			cout << "yes" << '\n';
		}
	}
	return 0;
}
