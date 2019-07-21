#include<bits/stdc++.h>
using namespace std;
long long int h(long long int n)
{
    long long int ans=0,t=sqrt(n);
    for(int i=1;i<=t;i++)
    {
        ans+=(n/i);
        int t=(n/i) - (n/(i+1));
        if(t>0)
        {
            ans+=(t*i);
        }
    }
    if(t==n/t)
        ans-=t;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        long long int n;
        cin >> n;
        cout << "Case " << qq << ": " << h(n) << '\n';
    }
    return 0;
}
