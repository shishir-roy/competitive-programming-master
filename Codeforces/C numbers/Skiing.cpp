#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define sf scanf
#define pf printf
int r,c;
int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};
int flag[1007][1007], ara[1007][1007];
void dfs(int ux,int uy)
{
    flag[ux][uy]=1;
    for(int i=0;i<4;i++)
    {
        int vx=ux+fx[i],vy=uy+fy[i];
        if( vx>=0 and vx<r and vy>=0 and vy<c and flag[vx][vy]==-1 and ara[vx][vy]<=ara[ux][uy] )
        {
            flag[vx][vy]=1;
            dfs(vx,vy);
        }
    }
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        sf("%d %d",&r,&c);
        vector< pair<int,pair<int,int>> >vt;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                sf("%d",&ara[i][j]);
                vt.push_back( { ara[i][j],{i,j} } );
            }
        }
        sort(vt.rbegin(),vt.rend());
        memset(flag,-1,sizeof flag);

        int cnt=0;
        for(int i=0;i<vt.size();i++)
        {
            int x=vt[i].second.first, y=vt[i].second.second;
            if(flag[x][y]==-1)
            {
//                cout << x << " " << y << endl;
                cnt++;
                dfs(x,y);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
