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
    int x,y;
    while(cin >> x >> y)
    {
    	int d=y-x;
    	int a=(y+d-1)/d;
    	cout << a << endl;
    }
    return 0;
}