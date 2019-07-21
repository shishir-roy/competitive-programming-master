#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define mod 1000000007
ll bigmod(ll b,ll p)
{
    ll ans=1;
    while(p>0)
    {
        if(p&1) ans=(ans*b)%mod;
        p>>=1;
        b=(b*b)%mod;
    }
    return ans%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    int k;
    cin >> k;
    ll ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0' || str[i]=='5')
        {
            ans+=bigmod(2,i);
            ans%=mod;
        }
    }

    ll n=str.size();
    ll t=bigmod(2,n)-1;
    ll s=( bigmod(2,k*n)-1 ) * bigmod(t,mod-2);
    s%=mod;

    cout << (ans*s)%mod << endl;
    return 0;
}
