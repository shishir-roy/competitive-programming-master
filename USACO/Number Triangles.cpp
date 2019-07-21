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
int bfs()
{
	int fx[]={1,1};
	int fy[]={0,1};
	queue< pair<int,int> >Q;
	Q.push({0,0});
	int flag[n+7][n+7];
	for(int i=0;i<n+7;i++)
	{
		for(int j=0;j<n+7;j++)
		{
			flag[i][j]=INT_MIN;
		}
	}
	flag[0][0]=ara[0][0];
	while(!Q.empty())
	{
		pair<int,int> u=Q.front();
		Q.pop();
		for(int i=0;i<2;i++)
		{
			int vx=u.first+fx[i];
			int vy=u.second+fy[i];
			if(vx>=0 and vx<n and vy>=0 and vy<n)
			{
				flag[vx][vy]=max(flag[vx][vy],flag[u.first][u.second]+ara[vx][vy]);
				Q.push({vx,vy});
			}
		}
	}
	int mx=0;
	for(int i=0;i<n;i++)
		mx=max(mx,flag[n-1][i]);
	cout << mx << endl;
}
int main()
{
//	freopen("numtri.in","r",stdin);
// 	freopen("numtri.out","w",stdout);
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    cin >> n;
    memset(ara,0,sizeof ara);
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i+1;j++)
    	{
    		cin >> ara[i][j];
    	}
    }
   /* for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cout << ara[i][j] << " ";
    	cout << endl;
    }
    cout << "#####" << endl;*/
    bfs();
    return 0;
}
