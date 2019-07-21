#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
int n,w,k,x[107],y[107];
ll dp[107][107];
ll rec(int ps,int t)
{
    if(ps>=n || t<=0) return 0;
    ll &ret=dp[ps][t];
    if(ret!=-1) return ret;
    int i;
    for(i=ps ;y[i]-y[ps]<=w && i<n ;i++ );
    ret=max(i-ps+rec(i,t-1),rec(ps+1,t));
    return ret;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        sf("%d %d %d",&n,&w,&k);
        for(int i=0 ;i<n ;i++ )
        {
            sf("%d %d",&x[i],&y[i]);
        }
        sort(y,y+n);
        memset(dp,-1,sizeof dp);
        ll ans=rec(0,k);
        pf("Case %d: %lld\n",qq,ans);
    }
    return 0;
}
/*

*/
