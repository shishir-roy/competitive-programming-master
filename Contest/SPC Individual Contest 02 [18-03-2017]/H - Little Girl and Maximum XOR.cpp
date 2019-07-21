#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
ll func(ll n)
{
	ll ans=1;
	while(n)
	{
		n>>=1;
		ans<<=1;
	}
	return ans;
}
int main()
{
//    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	ll l,r;
	cin >> l >> r;
	ll temp=l^r;
	ll ans=func(temp);
	cout << ans-1 ;
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

