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
    int n;
    cin >> n;
    if(n%7==0)
    {
    	for(int i=0;i<n/7;i++)
    	{
    		cout << 7;
    	}
    	return 0;
    }
    int s=0;
    int anf=-1,ans=-1;
     if(n%4==0)
    {
    	anf=n/4;
    	ans=0;
    }
    while(n>=7)
    {
    	n-=7;
    	s++;
    	if(n%4==0)
    	{
    		anf=n/4;
    		ans=s;
    	}
    }
    if(anf==-1 and ans==-1)
    	cout << -1 ;
    for(int i=0;i<anf;i++)
    	cout << 4 ;
    for(int i=0;i<ans;i++)
    	cout << 7;
    return 0;
}