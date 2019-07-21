/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 	string a,b;
 	cin >> a >> b;
 	int oa=0;
 	for(auto i:a)
 		if(i=='1')
 			oa++;
 	int ob=0;
 	for(auto i:b)
 		if(i=='1')
 			ob++;
 	if(oa>=ob)
 	{
 		cout << "YES";
 	}
 	else if(oa%2==1)
 	{
 		if(oa+1>=ob)
 		{
 			cout << "YES";
 		}
 		else
 		{
 			cout << "NO";
 		}
 	}
 	else
 	{
 		cout << "NO";
 	}
    return 0;
}