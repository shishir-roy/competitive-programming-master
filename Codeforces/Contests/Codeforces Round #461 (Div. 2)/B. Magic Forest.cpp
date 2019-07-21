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
int vis[2507][2507];
bool ok(int a,int b,int c)
{
    vector<int>vt;
    vt.push_back(a);
    vt.push_back(b);
    vt.push_back(c);
    sort(vt.begin(),vt.end());
    if(vt[2]<vt[1]+vt[0]) return 1;
    else return 0;
}
int main()
{
    int cnt=0;
    int n;
    cin >> n;
    for(int a=1;a<=n;a++)
    {
        for(int b=a+1;b<=n;b++)
        {
            int c = a^b ;
            if(vis[a][b] || vis[a][c] || vis[b][c])continue;
            if(c<=n and ok(a,b,c))
            {
                vis[a][b] = 1;
                vis[a][c] = 1;
                vis[b][c] = 1;
//                cout << a << " " << b << " " << c <<  endl;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
/*



*/
