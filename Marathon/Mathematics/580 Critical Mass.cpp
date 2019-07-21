#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int n;
ll dp[100007][5];
ll rec(int ps,int cnt)
{
    if(ps>=n) return 1;
    ll& ret=dp[ps][cnt];
    if(cnt==2)
    {
        ret=rec(ps+1,0);
    }
    else
    {
        ret=rec(ps+1,0);
        ret+=rec(ps+1,cnt+1);
    }
    return ret;
}
int main()
{
    while(cin >> n)
    {
        if(n==0) return 0;
        memset(dp,-1,sizeof dp);
        ll t=rec(0,0);
        cout << (1LL<<n) - t << endl;
    }
    return 0;
}
