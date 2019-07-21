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
    int n,c;
    sf("%d %d",&n,&c);
    int p[n+7],t[n+7];
    for(int i=0 ; i<n ; i++ )
    {
        sf("%d",&p[i]);
    }
    for(int i=0 ; i<n ; i++ )
    {
        sf("%d",&t[i]);
    }
    ll l=0,r=0,tt=0;
    for(int i=0; i<n ; i++ )
    {
        tt+=t[i];
        l+=max(0LL,p[i]-c*tt);
    }
    tt=0;
    for(int i=n-1; i>=0 ; i-- )
    {
        tt+=t[i];
        r+=max(0LL,p[i]-c*tt);
    }
//    cout << l << ' ' << r << endl;
    if(l==r) cout << "Tie";
    else if(l>r) cout << "Limak";
    else cout << "Radewoosh";
    return 0;
}
/*

*/
