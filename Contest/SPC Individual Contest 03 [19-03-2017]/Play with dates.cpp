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
bool leap(int y)
{
	if(y%4) return 0;
	if(y%100==0 and y%400==0) return 1;
	if(y%100==0) return 0;
	return 1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int tc;
	string days[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	int nd[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	cin >> tc;
	while(tc--)
	{
		int date,mon,year;
		cin >> date >> mon >> year ;
		int cnt=4;
		int md=0;	
		//cout << "INPUT NEWYA SESH" << endl;
		int flag=1;
		for(int y=2012;y<=year;y++)
		{
			for(int m=1;m<=12 and flag;m++)
			{	
				//if(y==2012 and m<=11) m=11;
				if(leap(y) and m==2)
				{
					md=29;
				}
				else md=nd[m];
				for(int d=1;d<=md and flag;d++)
				{
					if(y==2012 and m==1 and d<=11) d=11;
	
					//cout << "HI" << endl;
					//cout << d << " " << m << " " << y << endl;
					if(d==date and m==mon and y==year)
					{
						cout << days[cnt] << endl;
						flag=0;
					}
					cnt++;
					cnt%=7;
				}
			}
		}
		
	}				
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

