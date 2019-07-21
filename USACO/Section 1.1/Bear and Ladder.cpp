#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		if(a&1)
		{
			if(b==a-2 or b==a+1 or b==a+2)
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
		else
		{
			if(b==a-2 or b==a-1 or b==a+2)
			{
				cout << "YES" << '\n';
			}
			else 
			{
				cout << "NO" << '\n';
			}
		}
	}	
	return 0;
}
