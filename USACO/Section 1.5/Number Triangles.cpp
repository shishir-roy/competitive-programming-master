/*
ID:shishir10
LANG:C++11
TASK:numtri
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
int ara[1000+7][1000+7];
int flag[1000+7][1000+7];
int fx[]={1,1};
int fy[]={0,1};
/*int bfs()
{
	queue< pair<int,pair<int,int> > >Q;
	Q.push({0,{0,1}});
	while(!Q.empty())
	{
		pair<int,pair<int,int> > u=Q.front();
		Q.pop();
		for(int i=0;i<2;i++)
		{
			int vx=u.first+fx[i];
			int vy=u.second.first+fy[i];
			if(vx>=0 and vx<n and vy>=0 and vy<n and vx<u.second.second+1)
			{
				flag[vx][vy]=max(flag[vx][vy],flag[u.first][u.second.second]+ara[vx][vy]);
				Q.push({vx,{vy,u.second.second+1}});
			}
		}
	}
}*/
void dfs(pair<int,pair<int,int> >u)
{
	for(int i=0;i<2;i++)
	{
		int vx=u.first+fx[i];
		int vy=u.second.first+fy[i];
		if(vx>=0 and vx<n and vy>=0 and vy<n and vx<u.second.second+1)
		{
			flag[vx][vy]=max(flag[vx][vy],flag[u.first][u.second.second]+ara[vx][vy]);
			dfs({vx,{vy,u.second.second+1}});
		}
	}
}
int main()
{
/*	freopen("numtri.in","r",stdin);
 	freopen("numtri.out","w",stdout);*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(ara,0,sizeof ara);
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i+1;j++)
    	{
    		cin >> ara[i][j];
    	}
    }
    /*for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cout << ara[i][j] << " ";
    	cout << endl;
    }
    cout << "#####" << endl;*/
    /*bfs();*/
    for(int i=0;i<n+7;i++)
	{
		for(int j=0;j<n+7;j++)
		{
			flag[i][j]=INT_MIN;
		}
	}
	flag[0][0]=ara[0][0];
	dfs({0,{0,1}});
	int mx=0;
	for(int i=0;i<n;i++)
		mx=max(mx,flag[n-1][i]);
	cout << mx << endl;
    return 0;
}