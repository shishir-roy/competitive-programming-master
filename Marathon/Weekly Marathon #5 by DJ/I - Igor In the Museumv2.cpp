/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string>grid;
int ans=0;
int vis[1007][1007];
int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};
void dfs(int ux,int uy,int flag)
{
	if(flag==1)
	{
		vis[ux][uy]=ans;
	}
	if(flag==0)
	{
		vis[ux][uy]=1;
	}
	for(int i=0;i<4;i++)
	{
		int vx=ux+fx[i];
		int vy=uy+fy[i];
		if(flag==0 and grid[vx][vy]=='*')
		{
			ans++;
		}
		if(grid[vx][vy]=='.' and vis[vx][vy]==flag)
		{
			dfs(vx,vy,flag);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
    	string t;
    	cin >> t;
    	grid.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(grid[i][j]=='.' and vis[i][j]==0)
    		{
    			ans=0;
    			dfs(i,j,0);
    			dfs(i,j,1);
    		}
    	}
    }
    while(k--)
    {
    	int r,c;
    	cin >> r >> c;
    	r--,c--;
    	cout << vis[r][c] << endl;
    }
    return 0;
}