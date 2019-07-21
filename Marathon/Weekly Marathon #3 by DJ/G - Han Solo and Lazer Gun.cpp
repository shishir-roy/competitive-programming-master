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
 //   freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int n;
	cin >> n;
	double x,y;
	cin >> x >> y;
	set<double>st;
	int k=0;
	while(n--)
	{
		double a,b;
		cin >> a >> b;
		double d=a-x;	
		if(d!=0)
		{
			double t=(b-y)/d;
			st.insert(t);
			//cout << t << endl;
		}
		else k=1;
	}
	cout << st.size()+k;
	return 0;
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

