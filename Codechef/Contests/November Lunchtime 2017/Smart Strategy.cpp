#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,q;
        cin >> n >> q;
        vector<int>vt;
        for(int i=0;i<n;i++)
        {
            int t;
            cin >> t;
            if(t!=1)
            {
                vt.push_back(t);
            }
        }

        sort(vt.rbegin(), vt.rend() );
        while(q--)
        {
            int ans;
            cin >> ans;
            for(int i : vt)
            {
                ans/=i;
                if(ans<1)
                {
                    break;
                }
            }
            cout << ans  << " ";
        }
        cout << endl;
    }
    return 0;
}
