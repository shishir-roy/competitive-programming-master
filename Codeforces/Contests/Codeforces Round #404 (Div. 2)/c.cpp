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
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,m;
    cin >> n >> m;
    const clock_t begin_time = clock();
	if(m>=n)
	{
		cout << n << endl;
		return 0;
	}
	else
	{
		ll a=2*(n-m);
		ll p=sqrt(a);
		while(p*p+p<a)
			p++;
		cout << p+m << endl;
	}
//    cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*
1000000000000000000 1
*/
