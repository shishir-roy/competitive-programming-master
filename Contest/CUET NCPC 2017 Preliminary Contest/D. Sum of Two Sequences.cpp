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
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        ll a1,d1,k1,a2,d2,k2;
        sf("%lld%lld%lld %lld%lld%lld",&a1,&d1,&k1,&a2,&d2,&k2);
        ll s1=k1*(2*a1+(k1-1)*d1)/2;
//        cout << s1 << endl;
        ll s2=k2*(2*a2+(k2-1)*d2)/2;
        pf("Case %d: %lld\n",qq,s1+s2);
    }
    return 0;
}
/*
5
100000 100000 100000 100000 100000 100000
*/
