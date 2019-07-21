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
    int tc;
    cin >> tc;
    while(tc--)
    {
    	ll k,a,b;
    	cin >> k >> a >> b;
    	ll c=min(a,b);
    	ll d=max(a,b);
    	ll e=d-c-1;
    	ll f=k-(e+2);
    	if(k&1)
    	{
    		cout << min(e,f) << endl;
    	}
    	else
    	{
    		if(abs(a-b)==k/2)
    		{
    			cout << 0 << endl;
    		}
    		else
    		{
    			cout << min(e,f) << endl;
    		}
    	}
    }
    return 0;
}