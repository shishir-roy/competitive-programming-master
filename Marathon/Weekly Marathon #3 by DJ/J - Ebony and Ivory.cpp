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
	ll a,b,c;
	cin >> a >> b >> c;
	if(!(c%a)) cout << "Yes" ;
	else if(!(c%b)) cout << "Yes" ;
	else
	{
		int f=1;
		ll tt=c;
		while(c>0)
		{
			if(c%a==0)
			{
				f=0;
				break;
			}
			c-=b;
		}
				
		while(tt>0)
                {
       
                        if(tt%b==0)
                        {
                                f=0;
                                break;
                        }
			tt-=a;
                }
	if(f) cout << "No" ;
		else  cout << "Yes";
	}
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

