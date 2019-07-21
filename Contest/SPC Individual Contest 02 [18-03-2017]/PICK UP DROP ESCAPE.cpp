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
int ara[78];
int n,k;
int mx=0;
void rec(int ps,int rem,int x)
{
//	cout << x << endl;
	if(ps>=n)
	{
		if(rem==0)
		{
			mx=max(mx,x);
		}
		return ;
	}
	rec(ps+1,rem-1,x^ara[ps]);
	rec(ps+1,rem,x);
}
int main()
{
 //   freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int tc;
	cin >> tc;
	while(tc--){
	cin >> n >> k ;
	for(int i=0;i<n;i++)
		cin >> ara[i];
	mx=0;
	rec(0,k,0);
	cout << mx  << '\n';
	}	
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/
