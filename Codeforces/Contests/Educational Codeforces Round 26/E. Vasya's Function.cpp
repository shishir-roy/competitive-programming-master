#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>primes;
void factor(ll n)
{
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                primes.push_back(i);
            }
        }
    }
    if(n!=1)
        primes.push_back(n);
}
ll find_max(ll a,ll b)
{
    ll mx=0;
    for(auto it:primes)
    {
        if(a%it==0)
        {
            mx=max(mx,(b/it)*it);
        }
    }
    return mx;
}
ll func(ll a,ll b)
{
    ll ans=0;
    while(b>0)
    {
        ll g=__gcd(a,b);
        a/=g;
        b/=g;
        ll nb=find_max(a,b);
        ans+=(b-nb);
        b=nb;
    }
    return ans;
}
int main()
{
    ll a,b;
    cin >> a >> b;
    factor(a);
    ll t=func(a,b);
    cout << t << '\n';
    return 0;
}
