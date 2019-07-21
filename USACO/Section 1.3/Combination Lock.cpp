/*
ID:shishir10
LANG:C++11
TASK:combo
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool f(int a,int b)
{
	if(abs(a-b)<=2) return 1;
	if(abs(a-b)>=n-2) return 1;
	return 0;
}
bool check(int i,int j,int k,int a,int b,int c)
{
	return ( f(i,a) and f(j,b) and f(k,c) );
}
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int a,b,c,d,e,f;
	cin >> n;
	cin >> a >> b >> c >> d >> e >> f ;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{	

				if( check(i,j,k,a,b,c) or check(i,j,k,d,e,f) )
				{
					cnt++;
		//			cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
