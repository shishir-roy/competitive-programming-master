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
    ll l,r;
    cin  >> l >> r ;
        unsigned long long int ara[56];
    ara[1]=1;
    for(int i=2;i<56;i++)
    {
        ara[i]=ara[i-1]*2;
    }
    if(l==r) cout << 0;

    else
    {
        int i=1;
        while(1)
        {
            if(ara[i++]>r)
            {
                break;
            }
        }
        cout << ara[i-1]-1 ;
    }
    return 0;
}
/*

*/
