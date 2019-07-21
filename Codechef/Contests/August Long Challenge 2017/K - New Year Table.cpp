/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi acos(-1.0)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double R,r;
    cin >> R >> r;
    int t=pi/asin(r/(R-r))+0.000000000001;
    /*cout << fixed << setprecision(10) <<  pi/asin(r/(R-r)) << endl;
    cout << t << endl;*/
    if(r<=R and n==1)
    {
    	cout << "YES" << endl;
    }
    else if(R==r and n>1)
    {
    	cout << "NO" << endl;
    }
    else if(n<=t)
    {
    	cout << "YES" << endl;
    }
    else
    {
    	cout << "NO" << endl;
    }
    return 0;
}