/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    if(n<m) swap(n,m);
    ll ans=0;
    if(k>n+m-2)
    {
    	cout << -1 ;
    	return 0;
    }
    else if(k<n-1)
    {
    	ans=max(m*(n/(k+1)),n*(m/(k+1)) );
    }
    else
    {
    	ans=max(m/(k-n+2),n/(k-m+2) );
    }
    cout << ans << endl;
    return 0;
}