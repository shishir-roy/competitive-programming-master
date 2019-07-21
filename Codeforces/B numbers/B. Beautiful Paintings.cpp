#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ara[1009];
    memset(ara,0,sizeof ara);
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        ara[t]++;
    }
    int mx=0;
    for(int i=0;i<1007;i++)
    {
        mx=max(mx,ara[i]);
    }
    cout << n-mx;
    return 0;
}
