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
	int n;
	cin >> n;
	vector< pair<int,int> > vt;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		vt.push_back(pair<int,int>(t,i) );
	}
	sort(vt.begin(),vt.end());
	int ps=-1;
	for(int i=0;i<n;i++)
	{
		if(vt[i].sc>ps)
			ps=vt[i].sc;
		vt[i].fs=vt[i].sc;
		vt[i].sc=ps-vt[i].sc-1;
	}
	sort(vt.begin(),vt.end());
	for(int i=0;i<n;i++)
	{
		cout  << vt[i].sc << " " ;
	}
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

