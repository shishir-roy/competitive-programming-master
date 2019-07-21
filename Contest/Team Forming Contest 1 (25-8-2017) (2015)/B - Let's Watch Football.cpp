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
    ll a,b,c;
    cin >> a >> b >> c;
    ll t=a*c-b*c;
    cout << (t+b-1)/b << endl;
    return 0;
}