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
    int n,k;
    cin >> n >> k;
    int t=0,day=0,prev=0;
    for(int i=0;i<n;i++)
    {
    	int tt;
    	cin >> tt;
    	tt+=prev;
    	if(tt>8)
 		{
 			t+=8;
 			prev=tt-8;
 		}   
 		else
 		{
 			t+=tt;
 			prev=0;
 		}
 		day++;
 		if(t>=k)
 		{
 			break;
 		}
    }
    if(t>=k)
    {
    	cout << day << endl;
    }
    else
    {
    	cout << -1 << endl;
    }
    return 0;
}