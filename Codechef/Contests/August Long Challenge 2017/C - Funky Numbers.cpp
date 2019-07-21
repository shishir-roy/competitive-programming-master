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
    vector<ll>vt;
    for(ll i=1;i<100007;i++)
    {
    	vt.push_back(i*(i+1)/2LL);
    }
    sort(vt.begin(),vt.end());
    ll n;
    cin >> n;
    for(int i=0;i<vt.size();i++)
    {
    	if(binary_search(vt.begin(),vt.end(),n-vt[i]))
    	{
    		cout << "YES" ;
    		return 0;
    	}
    }
    cout << "NO" ;
    return 0;
}