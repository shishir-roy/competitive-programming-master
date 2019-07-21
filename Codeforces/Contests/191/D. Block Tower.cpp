#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int n,m;
string grid[507];


int fx[] = {-1,1,0,0};
int fy[] = {0,0,-1,1};
int cnt=0;
vector< pair<char,pair<int,int> > >vt;
bool ok(int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<m) return 1;
    return 0;
}
int flag[507][507];
void dfs(int ux,int uy,int p=1)
{
    cnt++;
    for(int i=0; i<4; i++)
    {
        int vx = fx[i] + ux, vy = fy[i] + uy;
        if( ok(vx,vy) and flag[vx][vy]==-1 and grid[vx][vy]=='.')
        {
            flag[vx][vy]=1;
            dfs(vx,vy,1);
        }
    }
    if(p)
    {
        cnt+=2;
    }
}

void dfs_print(int ux,int uy,int p=1)
{

    cout << "B " << ux+1 << " " << uy+1 << endl;
    for(int i=0; i<4; i++)
    {
        int vx = fx[i] + ux, vy = fy[i] + uy;
        if( ok(vx,vy) and flag[vx][vy]==-1 and grid[vx][vy]=='.')
        {
            flag[vx][vy]=1;
            dfs_print(vx,vy,1);
        }
    }
    if(p)
    {
        cout << "D " << ux+1 << " " << uy+1 << endl;
        cout << "R " << ux+1 << " " << uy+1 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
    }
    memset(flag,-1,sizeof flag);


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( flag[i][j]==-1 && grid[i][j]=='.' )
            {
                flag[i][j]=1;
                dfs(i,j,0);
            }
        }
    }
    cout << cnt << endl;

    memset(flag,-1,sizeof flag);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( flag[i][j]==-1 && grid[i][j]=='.' )
            {
                flag[i][j]=1;
                dfs_print(i,j,0);
            }
        }
    }
    return 0;
}
