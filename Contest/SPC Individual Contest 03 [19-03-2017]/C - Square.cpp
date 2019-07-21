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
int d;
vector<int>vt;
vector<int>ara;
vector< vector<int> > all;
int flag[100000];
int temp[100000];
int n;
void rec(int ps)
{
	if(ps>=n)
	{
		int s=0;
		for(int i=0;i<vt.size();i++)
		{
			s+=vt[i];
		}
		if(s==d)
		{
			all.push_back(vt);
		}
		return;
	}
	vt.push_back(ara[ps]);
	rec(ps+1);
	vt.pop();
	rec(ps+1);
}
			
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int t;
			cin >> t;
			push_back(t)
			sum+=t;
		}
	//	sort(ara,ara+n);
		if(!(sum%4))
		{
			cout << "no" << '\n';
			continue;
		}
		else if(ara[n-1]>=sum/4)
		{
			cout << "no" << '\n';
			continue;
		}
		rec(0);
		if(all.size()<4)
		{
			cout << "no" << '\n';
		else
		{
			for(int i=0;i<all.size();i++)
			{
				for(int j=i+1;j<all.size();j++)
				{
					for(int k=j+1;j<all.size();j++)
					{
						for(int l=k+1;k<all.size();k++)
						{
							if(all[i]+all[j]+all[k]+all[l]==ara)
							{
								cout << "yes" << endl;
							}
						}
					}
				}
			}
		}
	}
	
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/


