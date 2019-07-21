/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll lcm(ll a,ll b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,mx=0;
    cin >> n;
    ll o=1;
    if(n>100)
    {
        o=n-100;
    }
//    cout << o << endl;
    for(ll a=o;a<=n;a++)
    {
    	for(ll b=o;b<=n;b++)
    	{
    		for(ll c=o;c<=n;c++)
    		{
    			ll t=lcm(a,lcm(b,c));
    			mx=max(mx,t);
    		}
    	}
    }
//    mx=max(mx,n*(n-1)*(n-2));
    cout << mx << endl;
    return 0;
}
