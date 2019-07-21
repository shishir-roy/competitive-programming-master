#include<bits/stdc++.h>
using namespace std;
int table[507][507][12];
int ara[507][507];
int n;
void prepocess(int row)
{
	for(int i=0;i<n;i++)
	{
		table[row][i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=0;(i+(1<<j)-1)<n;i++)
		{
			if(ara[row][table[row][i][j-1]]>ara[row][table[row][i+(1<<(j-1))][j-1]])
			{
				table[row][i][j]=table[row][i][j-1];
			}
			else
			{
				table[row][i][j]=table[row][i+(1<<(j-1))][j-1];
			}
		}
	}
}
int query(int row,int l,int r)
{
	int e=r-l+1;
	int t=log2(e);
	return std::max( ara[row][table[row][l][t]], ara[row][table[row][r-(1<<t)+1][t]] );
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        printf("Case %d:\n",qq);
        int q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&ara[i][j]);
        for(int i=0;i<n;i++) prepocess(i);
        /*cout << "test " << query(1,0,3) << endl;*/
        while(q--)
        {
            int p,q,s;
            scanf("%d %d %d",&p,&q,&s);
            int ans=INT_MIN;
            p--,q--;
            /*cout << p << " " << q << endl;
            cout << p+s-1 << " " << q+s-1 << endl;*/
            for(int i=p;i<=p+s-1;i++)
            {
                ans=max(ans,query(i,q,q+s-1));
            }
            printf("%d\n",ans );
        }
    }
    return 0;
}