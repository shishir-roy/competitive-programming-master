#include<bits/stdc++.h>
using namespace std;
vector<int>gh[10007];
vector< pair<int,int> >bridges;
int dis[10007],low[10007];
int ti=0;
void art(int u,int p)
{
    dis[u]=low[u]=ti++;
    for(int i=0;i<gh[u].size();i++)
    {
        int v=gh[u][i];
        if(v==p) continue;
        if(dis[v]==-1)
        {
            art(v,u);
            low[u]=min(low[u],low[v]);
            if(dis[u]<low[v])
            {
                bridges.push_back({min(u,v),max(u,v)});
            }
        }
        else low[u]=min(low[u],dis[v]);
    }
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        cin >> n;
        getchar();
        for(int i=0; i<=n; i++)
        {
            gh[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            string str;
            getline(cin,str);
            for(int i=0; i<str.size(); i++)
            {
                if(str[i]=='(' or str[i]==')')str[i]=' ';
            }
            stringstream ss;
            ss<<str;
            int u,nv;
            ss>>u,ss>>nv;
            int v;
            while(nv--)
            {
                ss>>v;
                gh[u].push_back(v);
            }
        }
        memset(dis,-1,sizeof dis);
        ti=0;
        bridges.clear();
        for(int i=0;i<n;i++)
        {
            if(dis[i]==-1)
            {
                art(i,-1);
            }
        }
        sort(bridges.begin(),bridges.end());
        cout << "Case " << qq << ":" << '\n';
        cout << bridges.size() << " critical links" << '\n';
//        cout << "kaaj sesh " << endl;
        for(int i=0;i<bridges.size();i++)
        {
            cout << bridges[i].first << " - " << bridges[i].second << '\n';
        }
    }

    return 0;
}
/*
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0
*/
