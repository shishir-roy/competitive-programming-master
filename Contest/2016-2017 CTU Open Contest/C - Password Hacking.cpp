#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        vector<double>vt;
        for(int i=0;i<n;i++)
        {
            string s;
            double t;
            cin >> s >> t;
            vt.push_back(t);
        }
        double ans=0.0;
        sort(vt.rbegin(),vt.rend());
        for(int i=0;i<vt.size();i++)
        {
            ans+=(vt[i]*(i+1.0));
//            cout << vt[i] << " " << ans << endl;
        }
        cout << setprecision(10) << ans << endl;
    }
    return 0;
}
