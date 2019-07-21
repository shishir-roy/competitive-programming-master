#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    vector<int>vt;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        vt.push_back(t);
    }
    vector<int>mn=vt;
    mn.push_back(2000000000);
    for(int i=n-1;i>=0;i--)
    {
        mn[i]=min(mn[i],mn[i+1]);
    }
    int mx=-1,step=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,vt[i]);
        if(mx<=mn[i+1])
        {
            step++;
            mx=-1;
        }
    }
    cout << step << endl;
    return 0;
}
