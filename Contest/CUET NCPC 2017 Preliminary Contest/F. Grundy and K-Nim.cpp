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
    int tc;
    sf("%d",&tc);
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        int n,q;
        sf("%d",&n);
        ll ara[n+7];
        for(int i=0 ; i<n ; i++ )
        {
            sf("%lld",&ara[i]);
        }
//        DB;
        pf("Case %d:\n",qq);
        sf("%d",&q);
        for(int ii=1 ; ii<=q ; ii++ )
        {
            ll t;
            sf("%lld",&t);
            ll x=0;
            for(int i=0 ; i<n ; i++ )
            {
                x=x^(ara[i]%(t+1));
            }
            if(x==0)
            {
                pf("Query %d: Lose\n",ii);
            }
            else
            {
                pf("Query %d: Win\n",ii);
            }
        }
    }
    return 0;
}
/*
1
3
3 5 5
2
2 4
*/
