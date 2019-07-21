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
vector<int>vt;
int d=0;
int f=0;
void rec(int ps,int sum)
{
//    cout << sum << endl;
	if(ps>=vt.size())
	{
		if(sum==d)
			f=1;
		return ;
	}
	if(f) return ;
	rec(ps+1,sum+vt[ps]);
	rec(ps+1,sum);
}

int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int tc;
	cin >> tc;
	getchar();
	while(tc--)
	{
        vt.clear();
		string str;
		getline(cin,str);
		int t=0;
		int ii=0;
		int ara[300];
		for(int i=0;i<str.size();i++)
		{
			if(str[i]==' ')
			{
				ara[ii++]=t;
				t=0;
			}
			else
			{
				t=t*10+str[i]-'0';
			}
		}
		ara[ii++]=t;
		int flag[308];
		memset(flag,0,sizeof flag);
//		for(int i=0;i<ii;i++)
//		{
//            cout << ara[i] << endl;
//		}
		for(int i=0;i<ii;i++)
		{
			flag[ara[i]]++;
		}
//		DB;
//        cout << flag[1] << endl;
		for(int i=0;i<300;i++)
		{
			if(flag[i]%2==1)
			{
				vt.push_back(i);
			}
		}
		int sum=0;
		for(int i=0;i<vt.size();i++)
		{
			sum+=vt[i];
		}
//		for(int i=0;i<vt.size();i++)
//        {
//            cout << vt[i] << endl;
//        }
		if(sum%2==1)
		{
			cout << "NO" << endl;
		}
		else
		{
			if(sum==0)
			{
//                DB;
				cout << "YES" << endl;
			}
			else
			{
				f=0;
				d=sum/2;
//				cout << "d " << d << endl;
//				DB;
//				DB;
				rec(0,0);
				if(f)
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}

	}
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*
3
2 3 4 1 2 5 10 50 3 50
*/
