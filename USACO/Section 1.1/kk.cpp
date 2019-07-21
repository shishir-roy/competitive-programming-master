#include<bits/stdc++.h>
using namespace std;
int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};
int cnt=0;
int ff=1;
char str[70][70];
int flag[70][70];
int n;
void dfs(pair<int,int>u,char ch)
{
	flag[u.first][u.second]=1;
	cnt++;
	for(int i=0;i<4 and ff;i++)
	{
		int tx=u.first+fx[i];
		int ty=u.second+fy[i];
		if(tx>=0 and tx<n and ty>=0 and ty<n and flag[tx][ty]==-1 )
		{
			if(str[tx][ty]=='?')
			{
                str[tx][ty]= ( (ch == 'P') ? 'B' : 'P') ;
				dfs({tx,ty},ch);
			}
			else if(str[tx][ty]==ch)
			{
				ff=0;
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	for(int qq=1;qq<=tc;qq++)
	{
		cin >> n;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		memset(flag,-1,sizeof flag);
		ff=1;
		for(int i=0;i<n and ff;i++)
		{
			for(int j=0;j<n and ff;j++)
			{
				if(str[i][j]=='G')
				{
					for(int k=0;k<4;k++)
					{
						int tx=i+fx[i];
						int ty=j+fy[i];
						if(tx>=0 and tx<n and ty>=0 and ty<n and str[tx][ty]=='G')
						{
							ff=0;
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=0;i<n and ff;i++)
		{
			for(int j=0;j<n and ff;j++)
			{
				if(str[i][j]=='B' and (flag[i][j]==-1) )
				{
					ans=1;
					dfs({i,j},'P');
				}
				else if(str[i][j]=='P' and (flag[i][j]==-1) )
				{
					ans=1;
					dfs({i,j},'B');
				}
			}
		}
//		for(int i=0;i<n;i++)
//		{
//			printf("%s\n",str[i]);
//		}
		if(!ff)
		{
			cout << 0 << '\n';
			continue;
		}
		long long int  one=0;
		long long int tr=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(str[i][j]=='?' and flag[i][j]==-1)
				{
					cnt=0;
					tr++;
					dfs({i,j},'*');
					if(cnt==1)
					{
						one++;
					}
				}
			}
		}
		//cout << "total region " << tr << " one " << one << endl;
		int pt[3000];
		pt[0]=1;
		for(int i=1;i<3000;i++)
		{
			long long int temp=pt[i-1]*2;
			temp%=1000000007;
			pt[i]=temp;
		}
		if(tr!=0)ans+=pt[tr];
		ans%=1000000007;
		for(int i=1;i<=one;i++)
		{
			ans+=pt[tr-i];
			ans%=1000000007;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
6
3
?..
.??
??.
*/
