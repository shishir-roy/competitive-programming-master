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
	string str;
	cin >> str;
	int n;
	if(str.size()==1)
	{
		n=str[0]-'0';
	}
	else
	{
		n=(str[str.size()-2]-'0')*10+(str[str.size()-1]-'0');
    }
    n%=4;
    if(n==0) cout << 4 ;
    else cout << 0;
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

