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
//    freopen("output.txt","w",stdout);
    int n,t;
    cin >> n;
    int ara[150];
    memset(ara,0,sizeof ara);
    for(int i=0 ;i<n ;i++ )
    {
        sf("%d",&t);
        ara[t]++;
    }
    int f=1;
    int cnt=0;
//    DB;
    while(f)
    {
        f=0;
        for(int i=102 ;i>=0 ;i-- )
        {
            if(ara[i]!=0 && f==0)
            {
                f=1;
            }
            if(ara[i]>0) ara[i]--;
        }
        cnt++;
    }
    cout << cnt-1 << '\n';
//    main();
    return 0;
}
/*

*/
