#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    vector<int>vt;
    cin >> n >> m;
    int fc[100007],b[100007];
    memset(fc,0,sizeof fc);
    for(int i=1; i<=n; i++)
    {
        int t;
        cin >> t;
        if(fc[t]!=0)
        {
            fc[t]=-1;
        }
        else
            fc[t]=i;
    }
    int ff=0;
    for(int i=0; i<m; i++)
    {
        int t;
        cin >> t;
        if(fc[t]==0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        if(fc[t]==-1)
        {
            ff=1;
        }
        else
        {
            vt.push_back(fc[t]);
        }
    }
    if(ff==1)
    {
        cout << "Ambiguity" << endl;
    }
    else
    {
        cout << "Possible" << endl;
        for(int i:vt)
            cout << i << " ";
    }
    return 0;
}
