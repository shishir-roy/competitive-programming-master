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
    	double n,v1,v2;
    	cin >> n >> v1 >> v2;
    	double s=sqrt(2)*n;
    	n*=2.0;
    	if(n/v2<s/v1)
    	{
    		cout << "Elevator" << endl;
    	}
    	else
    		{
    			cout << "Stairs" << endl;
    		}
    }
    return 0;
}