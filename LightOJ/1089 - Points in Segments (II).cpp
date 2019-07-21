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
#define maxn 50007
int n,q;
int l[maxn],r[maxn];
int main()
{

    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        sf("%d %d",&n,&q);
        for(int i=0 ;i<n ;i++ )
        {
            sf("%d %d",&l[i],&r[i]);
        }
        sort(l,l+n);
        sort(r,r+n);
        for(int i=0;i<n;i++) cout << l[i] << " ";
        cout << '\n';
        for(int i=0;i<n;i++) cout << r[i] <<" ";
        cout << '\n';
        int t;
        pf("Case %d:\n",qq);
        while(q--)
        {
            sf("%d",&t);
            int  ps1=upper_bound(l,l+n,t)-l;
            int  ps2=lower_bound(r,r+n,t)-r;
            cout << ps1 << ' ' << n-ps2 << endl;
//            cout << ps1 << ' ' << ps2 << endl;
            int ans=min(n-ps2,ps1);
            pf("%d\n",ans);
        }
    }
    return 0;
}
/*
1
10 5
6334 26500
15724 19169
11478 29358
24464 26962
5705 28145
16827 23281
491 9961
2995 11942
4827 5436
14604 32391
12382
17421
*/
