#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
int cnt[maxn],ara[maxn];
void divi(int n)
{
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cnt[i]++;
            if(i*i != n) cnt[n/i]++;
        }
    }
}

ll nc4(ll n)
{
    return n*(n-1)*(n-2)*(n-3)/24LL ;
}
ll solve()
{
    ll ans[maxn];
    for(int i=10007; i>=1; i--)
    {
        ans[i]=nc4(cnt[i]);
        for(int j=2*i; j<=10000; j+=i)
        {
            ans[i]-=ans[j];
        }
    }
    return ans[1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        memset(cnt,0,sizeof cnt);
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> ara[i];
            divi(ara[i]);
        }
        solve();
        cout << "Case " << qq << ": " << solve() << endl;
    }
    return 0;
}
