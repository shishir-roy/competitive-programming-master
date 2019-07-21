/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n,k;
    cin >> n >>k;
    int ara[50];
    memset(ara,0,sizeof ara);
    char ch;
    while(scanf("%c",&ch)==1)
    {
    	if(ch>='a' and ch<='z')
    	{
    		ara[ch-'a']++;
    	}
    	if(ch>='a' and ch<='z'  and ara[ch-'a']>k)
    	{
    		cout << "NO";
    		return 0;
    	}
    }
    cout << "YES";
    return 0;
}