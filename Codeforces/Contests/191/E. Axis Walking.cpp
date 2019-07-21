#include<bits/stdc++.h>
#define pii                   pair<int,int>
#define tii                   pair<int,pair<int,int> >
#define fs                    first
#define sc                    second
#define DB                    cout<<"*****"<<endl;

#define mod                   1000000007
#define inf                   1000000007
#define pi                    acos(-1.0)

#define sf                    scanf
#define pf                    printf
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
#define pcase(x)              printf("Case %d: ",x)

#define ll                    long long int
#define maxn                  100007
using namespace std;

bool chk(int n,int ps)
{
    return (bool)(n&(1<<ps));
}

int ara[27],sp[5];


vector<pii> subset_gen( vector<int>& vt )
{
    vector< pii > ans;
    int n=vt.size();
    int num=1<<n;
    for(int i=1;i<num;i++)
    {
        int cnt=0,sum=0;
        for(int j=0;j<7;j++)
        {
            if(chk(i,j))
            {
                cnt++;
                sum+=vt[j];
            }
        }
        ans.push_back( {sum,cnt} );
    }

    return ans;
}

map< int , int  >mp;
void subset_map( vector<int>& vt )
{
    int n=vt.size();
    int num=1<<n;
    for(int i=1;i<num;i++)
    {
        int cnt=0,sum=0;
        for(int j=0;j<7;j++)
        {
            if(chk(i,j))
            {
                cnt++;
                sum+=vt[j];
            }
        }
        mp[sum]=cnt;
    }
}
ll fac[27];
void fact()
{
    fac[1]=1;
    for(ll i=2;i<25;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    vector<int>temp={1,2,3};
    subset_gen( temp );
    fact();
    int n;
    sf1(n);
    int sum=0
    for(int i=0;i<n;i++)
    {
         sf1(ara[i]);
         sum+=ara[i];
    }

    int k;
    sf1(k);

    if(k==0)
    {
        pf1ll(fac[n]);
    }
    else if(k==1)
    {
        ll myans = fac[n];
        int mid=n/2;
        vector<int>f;
        for(int i=0;i<mid;i++)
        {
            f.push_back(ara[i]);
        }
        vector<pii>subf = subset_gen(f);

        vector<int>s;
        for(int i=mid;i<n;i++)
        {
            s.push_back(ara[i]);
        }
        subset_map(s);

        for(int i=0;i<subf.size();i++)
        {
            int b=sum-subf[i].first;
            int a=n-subf[i].second;
            if(mp[b]==a)
            {
                a*=subf[i].second;
                ans-=a;
            }
        }
    }
    return 0;
}
/*

*/






