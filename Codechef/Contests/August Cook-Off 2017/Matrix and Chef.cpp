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
    int n,q;
    cin >> n >> q;
    int ara[n+7][n+7];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin >> ara[i][j];
    	}
    }
    cout << ara[0][0] << endl;
    for(int i=1;i<n;i++)
    	cout << " " << ara[0][i];
    while(q--)
    {
    	int p;
    	cin >> p;
    	p--;
    	for(int i=0;i<n;i++)
    	{
    		int t;
    		cin >> t;
    		ara[p][i]=t;
    		ara[i][p]=t;
    	}
    	for(int i=0;i<n;i++)
    	{
    		
    	}
    }
    return 0;
}