#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    string x,y;
    cin >> x >> y;
    set<int>vt,ans;
    for(int i=0;i<y.size();i++)
    {
        vt.clear();
        int j,p;
        for(j=0,p=i;j<x.size() and p<y.size();j++,p++)
        {
            if(x[j]!=y[p] )
            {
//                cout << "   " << p << endl;
                vt.insert(j);
            }
        }
        if( (ans.size()==0 or vt.size()<ans.size() ) and j==x.size())
        {
            ans.clear();
            ans=vt;
        }
    }
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i+1 << " ";
    return 0;
}
