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
ll ara[maxn],sum=0;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> ara[i];
        sum+=ara[i];
    }
    if(sum%3)
    {
        cout << 0 << endl;
        return 0;
    }

    ll t=0,i;
    for(i=1;i<=n;i++)
    {
        t+=ara[i];
        if(t==sum/3)
        {
            i++;
            break;
        }
    }

    int j;
    t=0;
    for(j=n;j>=0;j--)
    {
        t+=ara[j];
        if(t==sum/3)
        {
            j--;
            break;
        }
    }

    cout << i << " " << j << endl;
    vector<int>vt;
    for(;i<=j;i++)
    {
        vt.push_back(ara[i]);
    }

    for(int i=0;i<vt.size();i++)
    {
        cout << vt[i] << " ";
    }
    for(int x : vt)
    {
        cout << x << " ";
    }
    return 0;
}
/*



*/
