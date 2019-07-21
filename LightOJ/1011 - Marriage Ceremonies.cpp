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
int on(int n,int ps)
{
   return (n|=(1<<ps));
}
int off(int n,int ps)
{
    return n=n&~(1<<ps);
}
bool check(int n,int ps)
{
    return (bool) (n&(1<<ps));
}
int n;
int ara[20][20];
int dp[(1<<17)+7][17];
int rec(int mask,int men)
{
    if(mask==(1<<n)-1 and men>=n) return 0;
    int &ret=dp[mask][men];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0 ;i<n ;i++ )
    {
        if(check(mask,i)==0)
        {
            int mn=ara[i][men]+rec(on(mask,i),men+1);
            ret=max(mn,ret);
        }
    }
    return ret;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        sf("%d",&n);
        for(int i=0 ;i<n ;i++ )
        {
            for(int j=0 ;j<n ;j++ )
            {
                sf("%d",&ara[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        int ans=rec(0,0);
        pf("Case %d: %d\n",qq,ans);
    }
    return 0;
}
/*

*/
