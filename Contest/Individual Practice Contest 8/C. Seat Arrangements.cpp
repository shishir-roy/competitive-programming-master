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

#define maxn 1000007
ll fact[3000];
ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    ll a = fact[n]/(fact[r]*fact[n-r]);
    return (n-r)+1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    fact[0]=1;
    for(ll i=1;i<2207;i++)
    {
        fact[i] =  fact[i-1]*i;
    }
    ll n,m,k;
    cin >> n >> m >> k;

    vector<string>str;
//    cout << "okk" << endl;
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t ;
        str.push_back(t);
    }

    ll ans =0;
    for(int i=0;i<n;i++)
    {
        int t=0;
        for(int j=0;j<m;j++)
        {
            if(str[i][j] =='*')
            {
                ans+=ncr(t,k);
                t=0;
            }
            else
            {
                t++;
            }
        }
        ans+=ncr(t,k);
    }

    for(int i=0;i<m;i++)
    {
        int t=0;
        for(int j=0;j<n;j++)
        {
            if(str[j][i] =='*')
            {
                ans+=ncr(t,k);
                t=0;
            }
            else
            {
                t++;
            }
        }
        ans+=ncr(t,k);
    }
    cout << ans << endl;
    return 0;
}
/*


*/
