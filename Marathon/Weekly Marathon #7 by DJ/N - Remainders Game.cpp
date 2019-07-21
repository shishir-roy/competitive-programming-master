/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll lcm(ll a,ll b)
{
	return a*b/__gcd(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll temp=1;
    while(n--)
   {
   		ll t;
   		cin >> t;
   		temp=__gcd(k,lcm(temp,t));
   }
   if(temp==k)
   {
   		cout << "YES";
   }
   else
   {
   		cout << "NO";
   }
    return 0;
}