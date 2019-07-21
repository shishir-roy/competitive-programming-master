
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll  fac[22];

ll ways(vector<int>& vt)
{
    int t=0;
    ll den=1;
    for(int i=0; i<vt.size(); i++)
    {
        den*=fac[vt[i]];
        t+=vt[i];
    }
    return fac[t]/den;
}


void solve()
{
    string str;
    int n;
    cin >> str >> n;


    vector<int>vt(30);
    for(int i=0; i<str.size(); i++)
        vt[str[i]-'a']++;
    if(ways(vt)<n)
    {
        cout << "Impossible" << endl;
        return ;
    }

//    cout << ways(vt) << "fine" << endl;
    string ans;
    for(int i=0; i<str.size(); i++)
    {
        for(int j=0;j<vt.size();j++)
        {
            if(vt[j])
            {
                vt[j]--;
                if(ways(vt)>=n)
                {
                    ans+=('a'+j);
                    break;
                }
                else
                {
                    n-=ways(vt);
                    vt[j]++;
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    fac[1]=1,fac[0]=1;
    for(ll i=2; i<22; i++)
        fac[i]=i*fac[i-1];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cout << "Case " << qq << ": ";
        solve();
    }
    return 0;
}
