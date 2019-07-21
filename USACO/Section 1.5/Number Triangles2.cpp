/*
ID:shishir10
LANG:C++11
TASK:numtri
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf

int n;
int ara[1000+7][1000+7];
int fx[]={1,1};
int fy[]={0,1};
bool ok(int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<n and y<=x ) return true;
    return false;
}

int mx=0;
int dp[1007][1007];
int solve(int x,int y)
{
    if(y>x) return 0;
    if(x==n-1)
    {
        return ara[x][y];
    }
    int &ret=dp[x][y];
    if(ret != -1) return ret;
    for(int i=0;i<2;i++)
    {
        int tx = x+fx[i] ;
        int ty = y+fy[i] ;
        if( ok(tx,ty))
        {
            ret=max(ret,ara[x][y]+solve(tx,ty) );
        }
    }
    return ret;
}
int main()
{
	freopen("numtri.in","r",stdin);
 	freopen("numtri.out","w",stdout);
    sf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i+1;j++)
    	{
    		sf("%d",&ara[i][j]);
    	}
    }
    memset(dp,-1,sizeof dp);
	pf("%d\n",solve(0,0));
    return 0;
}
