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
int a,b,n,m,t,l=1;
inline ll h(ll i)
{
    return a+(i-1)*b;
}
inline ll sum(int r)
{
    if(h(r)>t) return false;
    int n=r-l+1;
    ll ans=(ll) 2LL*h(l)+(n-1)*b;
    ans=ans*n/2;
    if(ans>(ll)m*t)
        return false;
    return true;
}
int main()
{
    cin >> a >> b >>  n;
    while(n--)
    {
        sf("%d %d %d",&l,&t,&m);
        if(h(l)>t)
        {
            cout << "-1" << '\n';
            continue;
        }
        int r=max(t,m)+l,res;
        int left=l;
        while(left<=r)
        {
            int mid=(left+r)/2;
            if(sum(mid)){
                left=mid+1;
                res=mid;
            }
            else r=mid-1;
        }
        cout << res << endl;
    }
    return 0;
}
/*
2 3 100000
148990 913922 18257
2 1 4
7 10 2
*/
