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
    	double r;
    	cin >> r;
    	double d=1/sqrt(2);
    	double ans=r/(1-d);
    	cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}