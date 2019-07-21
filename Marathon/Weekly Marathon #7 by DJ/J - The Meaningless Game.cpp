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
    int n;
    cin >> n;
    while(n--)
    {
    	ll a,b;
    	cin >> a >> b;
    	ll mult=a*b;
    	ll t=pow(mult,1.0/3.0)-2;
    	while(t*t*t<mult)
    	{
    		t++;
    	}
    	if(t*t*t==mult and a%t==0 and b%t==0)
    	{
    		cout << "YES" << endl;
    	}
    	else
    	{
    		cout << "NO" << endl;
    	}
    }
    return 0;
}