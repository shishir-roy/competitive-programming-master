#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int n,m;
string grid[507];


int fx[] = {-1,1,0,0};
int fy[] = {0,0,-1,1};

vector< pair<char,pair<int,int> > >vt;
bool ok(int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<m) return 1;
    return 0;
}
int flag[507][507];
void dfs(int ux,int uy)
{
    for(int i=0;i<4;i++)
    {
        int vx = fx[i] + ux , vy = fy[i] + uy;
        if( ok(vx,vy) and flag[vx][vy]==-1 and grid[vx][vy]=='.')
        {
            vt.push_back( {'B', {vx,vy} } );
            flag[vx][vy]=1;
            dfs(vx,vy);
        }
    }
    vt.push_back( {'D', {ux,uy} } );
    vt.push_back( {'R', {ux,uy} } );
}


int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> grid[i];
    }
    memset(flag,-1,sizeof flag);

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( flag[i][j]==-1 && grid[i][j]=='.' )
            {
                vt.push_back( {'B', {i,j} } );
                flag[i][j]=1;
                dfs(i,j);
                vt.pop_back();
                vt.pop_back();
                cnt++;
            }
        }
    }
    cout <<vt.size() << endl;
    for(int i=0;i<vt.size();i++)
    {
//        printf("%c %d %d\n",vt[i].first,vt[i].second.first+1 , vt[i].second.second+1);
        cout << vt[i].first << " " << vt[i].second.first+1 << " " << vt[i].second.second+1 << '\n';
//        cout << vt[i].first << " " << vt[i].second.first+1 << " " << vt[i].second.second+1 << endl;
    }
//    cout << cnt << endl;
    return 0;
}
