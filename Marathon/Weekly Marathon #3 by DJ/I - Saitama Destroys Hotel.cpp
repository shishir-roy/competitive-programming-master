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
bool cmp(pii a, pii b)
{
	if(a.fs>b.fs)
		return 1;
	else return 0;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int n,top;
	cin >> n >> top;
	ll sum=0;
	vector<pii>vt;
	for(int i=0;i<n;i++)
	{
		int f,t;
		cin >> f >> t;
		vt.push_back({f,t});
	}
	sort(vt.begin(),vt.end(),cmp);
	int l=top;
	for(int i=0;i<n;i++)
	{
		sum+=(l-vt[i].fs);
		l=vt[i].fs;
		if(sum<vt[i].sc)
		{
			sum+=(vt[i].sc-sum);
		}
	}
	sum+=(l-0);
	cout  << sum << endl;	
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

