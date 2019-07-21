/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	const clock_t begin_time = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin >> a >> b;
    ll temp=a^b;
    ll ans=1;
    while(temp)
    {
    	ans<<=1;
    	temp>>=1;
    }
    cout << ans-1 ;
    /*cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;*/
    return 0;
}