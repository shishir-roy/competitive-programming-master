#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
#define mod                   1000000007
#define inf                   INT_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 1000000000000000000
vector<ll>xs,ys;
void rec(const vector<ll>&in, vector<ll>&out,ll cur,int ps)
{
    if(cur>maxn)
    {
        return ;
    }
    out.push_back(cur);
    for(int i=ps; i<in.size(); i++)
    {
        if(cur<=maxn/in[i])
        {
            rec(in,out,cur*in[i],i);
        }
    }
}
ll f(ll t)
{
    ll res = 0;
    ll yidx = 0;
    for(ll x : xs)
    {
        while(yidx<ys.size() && ys[yidx]<=t/x)
        {
            yidx++;
        }
        res+=yidx;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll>vt[3];
    for(int i=0; i<n; i++)
    {
        ll t;
        cin >> t;
        vt[i%2].push_back(t);
    }
    rec(vt[0],xs,1LL,0);
    rec(vt[1],ys,1LL,0);

    sort(xs.rbegin(),xs.rend());
    sort(ys.begin(),ys.end());
    ll l=1,r=maxn+7;
//    for(int x : xs)
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//    for(int x : ys)
//    {
//        cout << x << " ";
//    }
//    cout << endl << endl;
    ll k;
    cin >> k;
    while(l<r)
    {
        ll mid = (l+r)/2;
        ll t = f(mid);
        if(t<k)
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}
/*



*/
