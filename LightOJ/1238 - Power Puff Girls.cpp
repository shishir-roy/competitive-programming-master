#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
char str[25][25];
int n,m;
int dis[25][25];
pii des;
vector<pii>vt;
void Input()
{
    vt.clear();
    char ch;
    sf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++ )
    {
        for(int j=0 ; j<m ; j++ )
        {
            while(1)
            {
                sf("%c",&ch);
                if(ch=='a' || ch=='b' || ch=='c')
                {
                    str[i][j]=ch;
                    vt.push_back({i,j});
                    break;
                }
                else if(ch=='m'|| ch=='#')
                {
                    str[i][j]='#';
                    break;
                }

                else if(ch=='h')
                {
                    str[i][j]='.';
                    des={i,j};
                    break;
                }
                else if(ch=='.')
                {
                    str[i][j]=ch;
                    break;
                }
            }
        }
    }
}
int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};
int bfs(pii st)
{
    memset(dis,-1,sizeof dis);
    queue<pii>Q;
    Q.push(st);
    dis[st.fs][st.sc]=0;
    while(!Q.empty())
    {
        pii u=Q.front();
        Q.pop();
        for(int i=0 ;i<4 ;i++ )
        {
            int tx=u.fs+fx[i],ty=u.sc+fy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m && dis[tx][ty]==-1 && str[tx][ty]!='m'&& str[tx][ty]!='#')
            {
                dis[tx][ty]=1+dis[u.fs][u.sc];
                if(des.fs==tx && des.sc==ty ) return dis[tx][ty];
                Q.push({tx,ty});
            }
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        Input();
        int ans=INT_MIN;
        for(int i=0 ;i<vt.size() ;i++ )
        {
            int d=bfs(vt[i]);
            ans=max(ans,d);
        }
        pf("Case %d: %d\n",qq,ans);
    }
    return 0;
}
/*

*/
