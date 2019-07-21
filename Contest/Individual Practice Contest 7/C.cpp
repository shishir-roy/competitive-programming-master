#include<bits/stdc++.h>
using namespace std;

int n,m,ara[100][100],flag[100][100];
int fx[] = {1,-1,0,0,1,-1,1,-1};
int fy[] = {0,0,1,-1,1,1,-1,-1};
bool ok(int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<m)
    {
        return 1;
    }
    else
        return 0;
}

int cnt=0;
void dfs(int x,int y)
{
    cnt++;
    flag[x][y] = 1;
    for(int i=0;i<8;i++)
    {
        int tx = x + fx[i];
        int ty = y + fy[i];
        if(ok(tx,ty) and flag[tx][ty] == -1 and ara[tx][ty]==1)
        {
            dfs(tx,ty);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> ara[i][j];
        }
    }

    memset(flag,-1,sizeof flag);
    int ans =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(flag[i][j] == -1)
            {
                cnt=1;
                dfs(i,j);
                ans = max(ans,cnt);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
