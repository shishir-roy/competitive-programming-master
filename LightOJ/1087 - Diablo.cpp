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
	int tc;
	sf("%d",&tc);
	for(int qq=1;qq<=tc;qq++)
	{
		int n,q;
		sf("%d %d",&n,&q);
		vector<int>vt;
		for(int i=0;i<n;i++)
		{
			int t;
			sf("%d",&t);
			vt.push_back(t);
		}
		pf("Case %d:\n",qq);
		while(q--)
		{
			char ch;
			int id;
			sf(" %c %d",&ch,&id);
			if(ch=='a')
			{
				vt.push_back(id);
			}
			else
			{
				if(id>vt.size())
				{
					pf("none\n");
					continue;
				}
				pf("%d\n",vt[id-1]);
				vt.erase(vt.begin()+id-1);
			}
		}
	}
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

