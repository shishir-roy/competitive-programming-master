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
    for(int qq=1;qq<=tc;qq++)
    {
    	int n,m,k;
    	cin >> n >> m >> k;
    	int ara[n+7];
        ara[1]=1,ara[2]=2,ara[3]=3;
        for(int i=4;i<=n;i++)
        {
            ara[i]=(ara[i-1]+ara[i-2]+ara[i-3])%m+1;
        }
	    if(mn!=INT_MAX)
	    {
	    	cout << "Case " << qq << ": " << mn << endl;
	    }
	    else
	    {
	    	cout << "Case " << qq << ": " << "sequence nai" << endl;
	    }
    }
    return 0;
}
