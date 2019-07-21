#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        long long int n;
        cin >> n;
        vector<int>vt;
        for(int i=0;i<n;i++)
        {
            int t;
            cin >> t;
            vt.push_back(t);
        }
        sort(vt.begin(),vt.end());
        long long int ans=0;
        long long int nc=(n*(n-1)*(n-2))/(6);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int t=vt.size()-( upper_bound(vt.begin(),vt.end(),vt[i]+vt[j]-1)-vt.begin() );
                ans+=t;
            }
        }
        cout << "Case " << qq << ": " << nc-ans << '\n';
    }
    return 0;
}
