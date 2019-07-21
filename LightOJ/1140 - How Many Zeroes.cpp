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
char str[12];
ll dp[12][3][3][300],l;
ll rec(int ps,int isst,int issmall,ll val)
{
    if(ps>=l)
    {
        return val;
    }
    ll &ret=dp[ps][isst][issmall][val];
    if(ret!=-1)
        return ret;
    ret=0;
    int d= issmall==1 ? str[ps]-'0' : 9;
    if(isst)
        ret+=rec(ps+1,isst,d>0?0:issmall,val+1);
    else ret+=rec(ps+1,isst,0,val);
    for(int i=1 ; i<=d ; i++ )
    {
        ret+=rec(ps+1,1,i<d?0:issmall,val);
    }
    return ret;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        ll a,b,aa;
        sf("%lld %lld",&a,&b);
        if(a==0)
        {
            aa=0;
        }
        else
        {
            l=sprintf(str,"%lld",a-1);
            memset(dp,-1,sizeof dp);
            aa=rec(0,0,1,0)+1;
        }
        l=sprintf(str,"%lld",b);
        memset(dp,-1,sizeof dp);
        ll bb=rec(0,0,1,0)+1;
        pf("Case %d: %lld\n",qq,bb-aa);
    }
    return 0;
}
/*
5
100 200

*/
