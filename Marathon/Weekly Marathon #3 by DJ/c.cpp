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
/*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
//    const clock_t begin_time = clock();
	int n;
	cin >> n;
	vector<int>vt;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		vt.push_back(t);
	}
	sort(vt.begin(),vt.end());
	vector<ll>sums;
	sums.push_back(vt[0]);
	for(int i=1;i<n;i++)
	{
		sums.push_back(sums.back()+vt[i]);
	}
	ll ans=sums.back();
	for(int i=0;i<n-1;i++)
	{
		ans+=vt[i];
		ans+=(sums.back()-sums[i]);
	}
	cout << ans <<endl;
		//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/
