#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        cin >> n;
        vector<int>vt;
        vt.push_back(2);
        for(int i=0;i<n;i++)
        {
            int t;
            cin >> t;
            vt.push_back(t);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            double t=vt[i]-vt[i-1];
            if(t>0.5)
                ans+=ceil(t/5.0);
        }
        cout << "Case " << qq << ": " << ans << '\n';
    }
    return 0;
}
