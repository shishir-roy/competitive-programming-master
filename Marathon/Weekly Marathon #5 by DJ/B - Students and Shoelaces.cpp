/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int deg[n+7];
    memset(deg,0,sizeof deg);
    vector<int>gr[n+7];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int cnt=0;
    while(1)
    {
        vector<int>temp;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==1)
            {
                temp.push_back(i);
            }
        }
        for(auto i:temp)
        {
            f=1;
            /*cout << i << " ";*/
            for(auto j:gr[i])
            {
                deg[i]--;
                deg[j]--;
            }
        }
        /*cout << endl;*/
        if(!f)break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}