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
    int n,k;
    cin >> n >> k ;
    int d=n/2;
    if(n%2==1)
        d++;
    if(k>d or k==1)
    {
        cout << "-1" ;
    }
    else
    {
        cout << n-1 << endl;
        for(int i=1 ;i<n ;i++ )
        {
            cout << i << ' ' << i+1 << '\n';
        }
    }
    return 0;
}
/*

*/
