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

#define maxn 100007
int ara[6000],flag[6000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    map<string,string>mp;
    for(int i=0;i<n;i++)
    {
        string name,ip;
        cin >> name >> ip;
        mp[ip]=name;
    }
    for(int i=0;i<m;i++)
    {
        string a,b;
        cin >> a >> b;
        int sz=b.size();
        string c = b.substr(0,sz-1);
        cout << a << " " << b << " #" << mp[c] << endl;
//        cout << c << endl;
    }
    return 0;
}
/*



*/
