/*input

*/
#include<bits/stdc++.h>
#define ll long long int
#define maxn 100007
int table[maxn][20];
int vt[maxn];
int n;
// AC code
void prepocess()
{
	for(int i=0;i<n;i++)
	{
		table[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=0;(i+(1<<j)-1)<n;i++)
		{
			if(vt[table[i][j-1]]<vt[table[i+(1<<(j-1))][j-1]])
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
	int t=log2(e);
	return std::min( vt[table[l][t]], vt[table[r-(1<<t)+1][t]] );
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
    	int q;
    	scanf("%d %d",&n,&q);
    	for(int i=0;i<n;i++)
    	{
    		scanf("%d",&vt[i]);
    	}
    	prepocess();
    	printf("Case %d:\n",qq);
    	while(q--)
    	{
    		int l,r;
    		scanf("%d %d",&l,&r);
    		l--,r--;
    		printf("%d\n",query(l,r));
    	}
    }
    return 0;
}
