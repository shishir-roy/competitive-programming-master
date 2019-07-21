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
    	double d;
    	cin >> d;
    	cout << fixed << setprecision(2) << .5*d*d << endl;
    }
    return 0;
}