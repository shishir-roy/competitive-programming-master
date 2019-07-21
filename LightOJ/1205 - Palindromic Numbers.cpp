#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define sf scanf
#define pf printf
char str[20];

ll dp[20][3];
int l;
ll rec(int ps,int flag)
{
    cout << ps << " " << l/2 << endl;
    if(ps>=l/2)
    {
        return 1;
    }
    ll &ret = dp[ps][flag] ;
    int d = flag==1 ? str[ps]-'0' : 9 ;

    ret=0;
    for(int i=0; i<=d; i++)
    {
        ret+= rec(ps+1,i<d ? 0 : flag );
    }
    return ret;
}
int main()
{
    l=sprintf(str,"%lld",33LL);
    memset(dp,-1,sizeof dp);
    if(l&1)l++;
    cout << l << "**" << endl;
    ll bb= rec(0,1);
    cout << bb << " final " << endl;



    int tc;
    sf("%lld", & tc);
    for(int qq=1; qq<=tc; qq++)
    {
        ll a,b;
        sf("%lld %lld", &a, &b);

        l=sprintf(str,"%lld",b);
        memset(dp,-1,sizeof dp);
        reverse(str,str+l);
        if(l&1)l++;
        cout << l << endl;
        ll bb= rec(0,1);
        cout << bb << endl;

        l = sprintf(str,"%lld",a-1);
        if(l&1)l++;
        cout << l << endl;
        ll aa= rec(0,0);
        cout << bb-aa << endl;
    }
    return 0;
}
