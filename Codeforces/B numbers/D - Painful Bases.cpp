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
bool check(ll num,int ps)
{
    return (bool)( num&(1<<ps) );
}
int sett(ll num,int ps)
{
    return num|=(1<<ps);
}
ll bse,k,l,s;
string str;
ll dp[(1<<17)][25];
ll rec(ll mask,ll num)
{
    if(mask>=l)
    {
        if(num%k==0)
            return 1;
        return 0;
    }
    ll &ret=dp[mask][num];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0 ;i<s ;i++ )
    {
        if(check(mask,i)==0)
        {
            int t=0;
            if(str[i]>='0' && str[i]<='9') t=str[i]-'0';
            else t=str[i]-'A'+10;
            ret+=rec(sett(mask,i),(num*bse+t)%k);
        }
    }
    return ret;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        sf("%lld %lld",&bse,&k);
        cin >> str;
        s=str.size();
        l=(1<<s)-1;
        memset(dp,-1,sizeof dp);
        ll ans=rec(0,0);
        pf("Case %d: %lld\n",qq,ans);
    }
    return 0;
}
/*

*/
