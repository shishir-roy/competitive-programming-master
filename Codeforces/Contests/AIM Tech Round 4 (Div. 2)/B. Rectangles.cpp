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
    int n,m;
    cin >> n >> m;
    int ara[100][100];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin >> ara[i][j];
    	}
    }
    ll pw[70];
    pw[0]=1;
    for(int i=1;i<70;i++)
    {
    	pw[i]=pw[i-1]*2LL;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	int o=0,z=0;
    	for(int j=0;j<m;j++)
    	{
    		if(ara[i][j]==1)
    		{
    			o++;
    		}
    		else
    			z++;
    	}
    	ans+=(pw[o]+pw[z]-2);
    }
    for(int i=0;i<m;i++)
    {
    	int o=0,z=0;
    	for(int j=0;j<n;j++)
    	{
    		if(ara[j][i]==1)
    		{
    			o++;
    		}
    		else
    			z++;
    	}
		ans+=(pw[o]+pw[z]-2);
    }
    cout << ans-(n*m);
    return 0;
}