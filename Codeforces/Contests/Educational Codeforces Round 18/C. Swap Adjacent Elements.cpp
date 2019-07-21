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


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ara[n+7],mn[n+7],mx[n+7];
    for(int i=0;i<n;i++)
    {
        cin >> ara[i];
    }

    string str;
    cin >> str;
    mx[0]=ara[0];
    for(int i=1;i<n;i++)
    {
        mx[i] = max(mx[i-1],ara[i]);
    }

    mn[n-1]=ara[n-1];
    for(int i=n-2;i>=0;i--)
    {
        mn[i] = min(mn[i+1],ara[i]);
    }

    int f=1;
    for(int i=0;i<n-1;i++)
    {
        if(str[i]=='0' and mn[i+1]< (i+1) )
        {
            f=0;
        }
        else if(str[i]=='0' and mx[i]>(i+1))
        {
            f=0;
        }
    }
    if(f)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
/*

for(int i=0;vt.size()-1;i++)
    {
        cout << vt[i] << " ";
    }
    cout << vt.back();

*/
