#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int k,d;
ll dp[600][43];
ll rec(int n,int f)
{
    if(n==0 and f==1)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    ll& ret=dp[n][f];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=1;i<=k;i++)
    {
        ret+=rec(n-i,i>=d?1:f);
        ret%=mod;
    }
    ret%=mod;
    return ret;
}
int main()
{
    int n;
    cin >> n >> k >> d;
    memset(dp,-1,sizeof dp);
    ll t=rec(n,0)%mod;
    cout << t << endl;
    return 0;
}
