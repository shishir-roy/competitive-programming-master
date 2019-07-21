#include<bits/stdc++.h>
using namespace std;
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
    sort(vt.begin(),vt.end());
    int mn=INT_MAX;
    for(int i=1;i<vt.size();i++)
    {
        mn=min(mn,abs(vt[i]-vt[i-1]));
    }
    int cnt=0;
    for(int i=1;i<vt.size();i++)
    {
        if(abs(vt[i]-vt[i-1])==mn)
        {
            cnt++;
        }
    }
    cout << mn << " " << cnt << '\n';
    return 0;
}
/*
        for(int j=i+1; j<vt.size(); j++)
        {
            if(abs(vt[i]-vt[j])==mn)
            {
                cnt++;
            }
        }
        */
