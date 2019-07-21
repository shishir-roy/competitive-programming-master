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

#define maxn 700007
int ara[maxn];

int main()
{

    ll s=0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> ara[i];
        s+=ara[i];
        ara[i]+=ara[i-1];
    }
    if(s%3)
    {
        cout << 0 << endl;
        return 0;
    }
    s/=3;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s==0)
        {
            if(ara[i]==0)
            cnt++;
        }
        else if(ara[i]%s==0)
        {
            cnt++;
        }
    }
    cout << cnt-2 << endl;
    return 0;
}
/*



*/
