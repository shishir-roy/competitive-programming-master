#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0)
#define dbug(x) cout<<x<<" "
using namespace std;
int main()
{
    FAST;
    int  n, s;
    while(cin>>n>>s)
    {
        long long a[n],sum = 0,low=0, ans = n+2;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            while(sum>=s)
            {
                ans=min(ans,i-low+1);
                sum-=a[low];
                low++;
            }
        }
        if(ans == n+2)ans = 0;
        cout<<ans<<'\n';
    }
    return 0;
}
