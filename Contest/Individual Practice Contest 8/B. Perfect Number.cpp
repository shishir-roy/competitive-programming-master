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

bool ok(int n)
{
    int d=0;
    while(n)
    {
        d+=(n%10);
        n/=10;
    }
    return d==10;
}
int main()
{

    vector<int>vt;
    int i=10;
    while(vt.size()<10007)
    {
        if(ok(i))
        {
            vt.push_back(i);
        }
        i++;
    }
    sort(vt.begin(),vt.end());
//    for(int i=0;i<=40;i++)
//    {
//        cout << vt[i] << " ";
//    }
    int n;
    cin >> n;
    cout << vt[n-1] << endl;
    return 0;
}
/*

C. Seat Arrangements

*/
