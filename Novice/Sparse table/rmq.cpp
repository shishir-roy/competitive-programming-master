#include<bits/stdc++.h>
using namespace std;
int table[100][9];
int ara[]={2,4,3,1,6,7,8,9,1,7};
void prep(int n)
{
	for(int i=0;i<n;i++)
	{
		table[i][0]=i;
	}
	for(int j=1;(1<<j)<n;j++)
	{
		for(int i=0;(i+(1<<j)-1)<n;i++)
		{
			if(ara[table[i][j-1] ]<ara[table[i+(1<<(j-1))][j-1] ])
			{
				table[i][j]=table[i][j-1];
			}
			else
			{
				table[i][j]=table[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int query(int l,int r)
{
	int e=r-l+1;
	int k=log(e);
	return min(ara[table[l][k]],ara[table[l+e-(1<<k)][k]]);
}
int main()
{
	int n=(sizeof ara)/(sizeof (int));
	prep(n);
	cout << query(4,7);
	return 0;
}
