#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool is_prime(ll t)
{
	if(t==1) return 0;
	else if(t==2) return 1;
	else if(t%2==0)	return 0;
	ll sq=sqrt(t);
	for(ll i=3;i<=sq;i+=2)
	{
		if(t%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		ll t;
		cin >> t;
		ll sq=sqrt(t);
		if(sq*sq==t and is_prime(sq) ) 
		{
			cout << "YES\n";
		}
		else 
		{
			cout << "NO\n";
		}
	}
	return 0;
}	
