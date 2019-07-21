#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int>vt;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        vt.push_back(t);
    }
    if(vt.size()==1)
    {
        cout << 1 << endl;
        cout << vt[0] << endl;
        return 0;
    }
    int t=__gcd(vt[0],vt[1]);
    for(int i=3;i<n;i++)
    {
        t=__gcd(t,vt[i]);
    }
    if(binary_search(vt.begin(),vt.end(),t)==0)
    {
        cout << -1 ;
        return 0;
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(vt[i]);
        ans.push_back(vt[0]);
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}
