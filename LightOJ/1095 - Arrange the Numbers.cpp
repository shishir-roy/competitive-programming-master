#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define mod 1000000007
ll fac[1007];
ll ncr[1007][1007];
void bio()
{
    for(int i=1;i<1007;i++)
    {
        ncr[i][0]=ncr[i][i]=1;
        ncr[i][1]=i;
        for(int j=2;j<i;j++)
        {
            ncr[i][j] = ( ncr[i-1][j] + ncr[i-1][j-1] )%mod;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bio();
    fac[0]=1;
    fac[1]=1;
    for(ll i=2;i<1007;i++)
    {
        fac[i] = ( fac[i-1] * i ) % mod;
    }

    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n,m,k;
        cin >> n >> m >> k;
        ll ans=ncr[m][k];
        ll x=n-k, y=m-k;
        ll temp=fac[x];


//        cout << "temp " << temp << " x " << x << endl;
        for(int i=1;i<=y;i++)
        {
            if(i&1) temp-=( ncr[y][i] * fac[x-i] ) %mod;
            else temp+= ( ncr[y][i] * fac[x-i] ) %mod;

            temp=(temp+mod)%mod;
        }

        cout << "Case " << qq << ": " << (ans*temp)%mod << endl;
    }

    return 0;
}
