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
    	int n;
    	cin >> n;
    	double ara[40];
    	ara[0]=0,ara[1]=1;
    	for(int i=2;i<40;i++)
    	{
    		ara[i]=ara[i-1]+ara[i-2];
    	}
    	double sum=0;
    	
    	for(int i=1;i<=n;i++)
    	{
    		sum+=ara[i]*ara[i]*(1.0-3.141593/4);
    	}
    	cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}