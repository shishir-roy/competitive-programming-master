#include <bits/stdc++.h>
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)  for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iOS  ios_base::sync_with_stdio(false)
#define sqr(a)  (((a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
#define umap  unordered_map
//#define max(x,y)  ((x) > (y) ? (x) : (y))
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
ll A,B,n,l,t,m,s;
inline ll comb(ll x)
{
    return (x * (x-1LL))/2LL;
}
inline ll h(ll i)
{
    return A + (i-1LL) * B;
}
inline bool check(ll r)
{
    ll e = comb(r) - comb(l-1LL);
//    if(B && (double)e  > 2e18 / (double)B)
//        return false;
    if(h(r) > t) return false;
    s = m * t;
    s -= e * B;
    s -= A * (r - l + 1LL);
    cout << r << " sum " << m*t-s << " m*t= " << m*t << endl;
    return (s >= 0LL);
}
int main()
{
    iOS;
    cin >> A >> B >> n;
    while(n --)
    {
        cin >> l >> t >> m;
        if(h(l) > t)
        {
            cout << -1 << '\n';
            continue;
        }
        ll lo = l, hi = max(t, m) + l + 5;
        while(lo < hi)
        {
            ll mid = (lo + hi)/2LL;
            if(check(mid))
                lo = mid;
            else
                hi = mid - 1LL;
//            cout << mid << ' ' << h(mid) << ' ' << check(mid) << endl;
            if(lo + 1LL == hi)
            {
                if(check(hi))
                    lo = hi;
                else
                    hi = lo;
            }
        }
        cout << lo << '\n';
    }
}
