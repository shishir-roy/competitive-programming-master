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
 	ll sum=0;
 	int f=1;
 	for(int i=0;i<n;i++)
 	{
 		int t;
 		cin >> t;
 		sum+=t;
 		if(t&1)
 			f=0;
 	} 
 	if(f)
 	{
 		cout << "Second" ;
 	} 
 	else 
 	{
 		cout << "First";
 	}
    return 0;
}