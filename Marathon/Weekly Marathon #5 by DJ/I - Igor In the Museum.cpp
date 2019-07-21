/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string>grid;
map< pair<int,int> , int >mp;
int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};
int cnt=0;
int flag[1007][1007];
vector< pair<int,int> > vt;
void dfs(int ux,int uy)
{
	flag[ux][uy]=1;
	for(int i=0;i<4;i++)
	{
		int vx=ux+fx[i];
		int vy=uy+fy[i];
		if(flag[vx][vy]==0)
		{
			if(grid[vx][vy]=='*')
			{
				cnt++;
			}
			else
			{
				vt.push_back({vx,vy});
				dfs(vx,vy);
			}
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
    while(k--)
    {
    	int r,c;
    	cin >> r >> c;
    	r--;
    	c--;
    	auto it=mp.find({r,c});
    	if(it!=mp.end())
    	{
    		cout << it->second << endl;
    	}
    	else
    	{
	    	cnt=0;
	    	vt.clear();
	    	memset(flag,0,sizeof flag);
	    	dfs(r,c);
	    	cout << cnt << endl;
	    	vt.push_back({r,c});
	    	for(auto it:vt)
	    	{
	    		mp[it]=cnt;
	    	}
    	}
    }
    return 0;
}