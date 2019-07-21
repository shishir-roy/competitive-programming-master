#include<bits/stdc++.h>
using namespace std;
#define mxn 5000507
#define mod 1000000007
int p[mxn+7];
void seive()
{
    for(int i=2; i<mxn; i+=2)
        p[i]=2;
    for(int i=3;i<mxn;i+=2)
    {
        if(!p[i])
        {
            for(int j=i;j<mxn;j+=i)
            {
                if(!p[j])p[j]=i;
            }
        }
    }
}
long long int dp[mxn+7];
long long int rec(long long int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 3;
    long long int& ret=dp[n];
    if(ret!=-1) return ret;
    ret=(n*(p[n]-1)/2)+ rec(n/p[n]);
    ret%=mod;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    seive();
    memset(dp,-1,sizeof dp);
    for(int i=1; i<mxn; i++)
    {
        dp[i]=rec(i);
    }
    long long int t,l,r;
    cin >> t >> l >> r;
    long long int tt=1,ans=0;
    for(int i=l; i<=r; i++)
    {
        long long int temp=tt*dp[i];
        ans+=(temp%mod);
        tt*=t;
        tt%=mod;
        ans%=mod;
    }
    cout << ans%mod;
    return 0;
}
// 1000000000 5000000 5000000
