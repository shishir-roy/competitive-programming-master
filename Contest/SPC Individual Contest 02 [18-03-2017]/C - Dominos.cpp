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
#define maxn 100007
stack<int>st;
vector<int>graph[maxn];
void dfs(int u)
{
    flag[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(flag[v]==-1)
        {
            dfs(v);
            st.push(v);
        }
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        st.clear();
        memset(flag,-1,sizeof flag);
        for(int i=1;i<=n;i++)
        {
            if(flag[i]==-1)
            {
                dfs(i);
            }
        }
        while()
    }
    return 0;
}
/*

*/
