#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigmod(ll a,ll b,ll m)
{
    /// a^b%m
    ll ans=1;
    while(b>0)
    {
        if(b&1LL)
            ans=(a*ans)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        string a,b;
        cin >> a >> b;
        cout << "Case " << qq << ": ";
        int f=1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!='0')
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            cout << 0 << endl;
            continue;
        }
        ll r=0;
        for(int i=0;i<a.size();i++)
        {
            r+=(1LL*(a[i]-'0') );
            r%=9LL;
        }
        if(r==0) r=9LL;

//        cout << "r " << r << endl;
        ll t=bigmod(r,10LL,9LL)%9LL;

        ll temp[b.size()+7];
        temp[b.size()-1]=r;
        for(int i=b.size()-2;i>=0;i--)
        {
            temp[i]=bigmod(temp[i+1],10LL,9LL)%9LL;
        }


        ll ans=1LL;
        for(int i=0;i<b.size();i++)
        {
            ans*=(bigmod(temp[i],(b[i]-'0')*1LL,9LL));
            ans%=9LL;
        }
        if(ans==0) ans=9LL;
        cout << ans << endl;
    }
    return 0;
}
