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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int d=n/2;
    for(int i=0;i<d;i++)
    {
    	if(str[i]=='R' && str[i+d]=='L')
    	{
    		cout << i+d+1 << " " << i+1 << endl;
    	}
    	else
    	{
    		cout << i+1 << " " << i+d+1 << endl;
    	}
    }
    return 0;
}