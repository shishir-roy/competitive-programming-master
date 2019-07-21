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
    int n;
    cin >> n;
    int digit=0;
    int ans=0;
    while(n>0)
    {
        if(n%10==7)
        {
            ans|=(1<<digit);
        }
        n/=10;
        digit++;
    }
    for(int i=1 ;i<digit ;i++ )
    {
        ans+=(1<<i);
    }
    cout << ans+1 << endl;
//    main();
    return 0;
}
/*

*/
