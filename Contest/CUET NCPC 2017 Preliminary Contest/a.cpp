#include<bits/stdc++.h>
#define LL long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mx 2000000009

using namespace std;

LL gcd(LL a,LL b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return  (a/gcd(a,b))*b;
}

int main()
{
    int tc,caseno=0;
    cin>>tc;
    while (tc--)
    {
        LL n,p;
        cin>>n>>p;
        p=100-p;
        LL lc=1;
        for (int i=2; i<=n; i++)
        {
            lc=lcm(lc,i);
        }
        printf("%lld \n",lc);
        LL nc=0;
        for (int i=1; i<=n; i++)
            nc+=lc/i;
        cout << nc << endl;
        nc=nc*100*n;
        lc=lc*p;
        printf("%lld \n",nc);
        LL gc=gcd(nc,lc);
        nc=nc/gc;
        lc=lc/gc;
        printf("Case %d: %lld/%lld\n",++caseno,nc,lc);
    }
    return 0;
}
