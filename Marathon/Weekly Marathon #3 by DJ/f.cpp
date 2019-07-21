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
ll convert(int ara[],int n,int b)
{
	ll ans=0;
	ll base=1;
	while(n--)
	{
		ans+=ara[n]*base;
		base*=b;
	}
//	ans+=ara[n]*base;
	return ans;
}
int main()
{
/*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
//    const clock_t begin_time = clock();
	int n,a;
	cin >> n >> a;
	int aa[n+7];
	for(int i=0;i<n;i++)
	{
		cin >> aa[i];
	}
	ll ca=convert(aa,n,a);
	int m,b;
	cin >> m >> b;
	int bb[m+7];
	for(int i=0;i<m;i++)
	{
		cin >> bb[i];
	}
	ll cb=convert(bb,m,b);
	//cout << "**** " << endl;
//	cout << ca << " " << cb << endl;
	if(ca==cb)cout << "=" << endl;
	else if(ca<cb) cout << "<" << endl;
	else cout << ">" << endl;
	//cout << ca << " " << cb << endl;
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/
