#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int>a;
    map<long long int,long long int>mp;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    if(a[0]==a[1] and a[1]==a[2])
    {
        long long int t=mp[a[0]];
        cout << t*(t-1)*(t-2)/6;
    }
    else if(a[0]!=a[1] and a[1]==a[2])
    {
        long long int t=mp[a[1]];
        cout << t*(t-1)/2;
    }
    else
    {
        cout << mp[a[2]] ;
    }
    return 0;
}
