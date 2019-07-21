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
int dp[12][93][93][3];
ll a,b,k;
int l;
char vt[12];
int rec(int ps,int dgt_sum,int num,int flag)
{
    if(ps==l)
    {
        if(dgt_sum%k==0 and num%k==0)
            return 1;
        return 0;
    }
    int &ret=dp[ps][dgt_sum][num][flag];
    if(ret!=-1)
        return ret;
    ret=0;
    int d= flag==1 ? vt[ps]-'0' : 9;
    for(int i=0 ;i<=d ;i++ )
    {
        ret+=rec(ps+1,(dgt_sum+i)%k,(num*10+i)%k,i<d?0:flag);
    }
    return ret;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        sf("%lld %lld %lld",&a,&b,&k);
        if(k>90) pf("Case %d: 0\n",qq);
        else if(k==1) pf("Case %d: %lld\n",qq,b-a+1);
        else
        {
            /// sprintf returns koi ta character newya hoice
            l=sprintf(vt,"%lld",a-1);
            memset(dp,-1,sizeof dp);
            int aa=rec(0,0,0,1);
            l=sprintf(vt,"%lld",b);
            memset(dp,-1,sizeof dp);
            int bb=rec(0,0,0,1);
            pf("Case %d: %d\n",qq,bb-aa);
        }
    }
    return 0;
}
/*

*/
