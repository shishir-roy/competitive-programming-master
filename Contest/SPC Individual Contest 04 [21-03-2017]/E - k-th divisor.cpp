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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	long long int n,k;
	cin >> n >> k;
	int sq=sqrt(n);
	vector<long long int>vt;
	for(int i=1;i<=sq;i++)
	{
		if(n%i==0)
		{
			vt.push_back(i);
			if(i!=(n/i))
			vt.push_back(n/i);
		}
	}
	sort(vt.begin(),vt.end());
	//cout << vt.size() << endl;
	if(vt.size()<k)
		cout << -1 ;
	else cout << vt[k-1];
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

