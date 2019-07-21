#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigmod(ll a,ll b,ll m)
{
    /// a^b%m
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(a*ans)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
}
ll egcd (ll a,ll b,ll &x,ll &y)
{
    /// ax+by=1 finding x and y where a<b
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd (b%a,a,x1,y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
ll modInv(ll a,ll m)
{
    /// works only when (a,m)=1;
    /// ax=1 (mod m) finding x
    ll x,y;
    if(a<=m)
        egcd(a,m,x,y);
    else
        egcd(m,a,y,x);
    x%=m;
    if(x<0) x+=m;
    /// if x can be very large nand m is prime then use big mod
//    x=bigmod(a,m-2,m)%m;
    return x;
}
ll ncr(ll n,ll r,ll p)
{
    if(n<r) return 0;
    r=min(r,n-r);
    ll nu=1,de=1;
    for(ll i=n; i>=n-r+1; i--)
    {
        nu=(nu*i)%p;
    }
    for(int i=1; i<=r; i++)
    {
        de=(de*i)%p;
    }
    ll mide=modInv(de,p)%p;
    ll t=(nu*mide)%p;
    return t;
}
ll Lucas(ll n, ll r, ll p)
{
    /// works only when p is prime
    if (n==0 && r==0) return 1;
    int ni = n % p;
    int mi = r % p;
    if (mi>ni) return 0;
    return Lucas(n/p, r/p, p) * ncr(ni, mi, p);
}
ll CRT(const vector< pair<int, int> > &vt)
{
    /// pair<ai(residues),pi(primes)>
 	ll M = 1;
 	for(int i = 0; i<vt.size(); i++)
 		M *= vt[i].second;
 	ll ret = 0;
 	for(int i = 0; i<vt.size(); i++)
 	{
 		ll ai = vt[i].first;
 		ll Mi = (M/vt[i].second);
 		ret += ai * Mi * modInv(Mi % vt[i].second, vt[i].second);
 		ret %= M;
 	}
 	return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n,r,m;
        cin >> n >> r >> m;
        vector< pair<int,int> > vt;
        for(int i=2;i<=50;i++)
        {
            if(m%i==0)
            {
                m/=i;
                ll t=Lucas(n,r,i);
                vt.push_back({t,i});
            }
        }
        ll ans=CRT(vt);
        cout << ans << endl;
    }
    return 0;
}
