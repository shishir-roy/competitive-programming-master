#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll m,n;
    cin >> n >> m;
    ll ans=( (m%mod)*(n%mod) )%mod;

    ll k=min(n,m);
    for(ll i=1;i*i<=k;i++)
    {
        ans-=(i*(n/i));
        while(ans<0) ans+=mod;
    }

    ll i=sqrt(k)-2;
    while(i*i<k)i++;

    if(k%i==0)
        i=sqrt(n)-1;
    else i=sqrt(n);
    for(;i>=1;i--)
    {
        ll u=min(n/i,k);
        ll l=n/(i+1);
        l++;
        ll t=u*(u+1)/2 - l*(l+1)/2;
        ans-=(t*i);
        while(ans<0) ans+=mod;
    }
    cout << ans%mod << endl;
    return 0;
}
