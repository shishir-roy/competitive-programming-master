#include<bits/stdc++.h>
using namespace std;
#define DB printf("*****\n")
#define sf scanf
#define pf printf
#define ll long long int
#define pii pair<int,int>
#define inf 2147483647
#define maxn 104
ll bidmod(ll b,ll p)
{
    ll ans=1;
    while(p>0)
    {
        if(p&1)
        {
            b%=1000000;
            ans=(ans*b)%1000;
        }
        b=(b*b)%1000;
        p>>=1;
    }
    return ans;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for (int qq=1; qq<=tc ; qq++ )
    {
        ll n,k;
        sf("%lld %lld",&n,&k);
        double t=(double)k * log(n)/log(10);
        int te=(int) t;
        double a=pow(10,t-(double)te);
        int ans=ceil(a*100.0);
        if(ans>=999.99) {ans/=10.0;}
        pf("Case %d: %0.lf ",qq,ans);
        int b=bidmod(n,k);
        if(b<10)
            pf("00%d\n",b);
        else if(b<99)
            pf("0%d\n",b);
        else pf("%d\n",b);
    }
    return 0;
}
/*
5
1000000000 10000000

*/
