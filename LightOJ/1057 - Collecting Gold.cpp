#include<bits/stdc++.h>
using namespace std;
vector<string>vt;
int dis[25][25];
int ng;
void generating_dis(int m,int n)
{
    vector<int>xx,yy;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vt[i][j]=='x')
            {
                vector<int>::iterator it;
                it=xx.begin();
                xx.insert(it,i);
                it=yy.begin();
                yy.insert(it,j);
            }
            else if(vt[i][j]=='g')
            {
                xx.push_back(i);
                yy.push_back(j);
            }
        }
    }
    memset(dis,0,sizeof dis);
    for(int i=0;i<xx.size();i++)
    {
        for(int j=0;j<xx.size();j++)
        {
            dis[i][j]=max(abs(xx[i]-xx[j]),abs(yy[i]-yy[j]));
        }
    }
    ng=xx.size();
}
int dp[1<<16][16];
int rec(int mask,int u)
{
    if(mask==(1<<ng)-1)
    {
        return dis[u][0];
    }
    int& ret=dp[mask][u];
    if(ret!=-1) return ret;
    ret=INT_MAX;
    for(int v=0;v<ng;v++)
    {
        if(!(mask&(1<<v)))
        {
            ret=min(ret,rec(mask|(1<<v),v)+dis[u][v]);
        }
    }
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int m,n;
        cin >> m >> n;
        vt.clear();
        for(int i=0;i<m;i++)
        {
            string t;
            cin >> t;
            vt.push_back(t);
        }
        generating_dis(m,n);
        memset(dp,-1,sizeof dp);
        int t=rec(0,0);
        cout << "Case " << qq << ": " << t << '\n';
    }
    return 0;
}
