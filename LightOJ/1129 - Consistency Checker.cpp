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

#define maxn 200007
#define next _next

int sz = 0 ;
int next[15][maxn];
int en[maxn];
bool created[maxn];

int flag = 1;
void insert(string &s)
{
    int v = 0;
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i] - '0';
        if(! created[next[c][v]])
        {
            next[c][v] = ++sz;
            created[sz] = true;
        }
        v = next[c][v];
        if(en[v]>0)
        {
            flag = 1;
        }
    }
    ++en[v];
}

void clr()
{
    sz  = 0;
    flag = 0;
    memset(created,false,sizeof created);
    memset(en,0,sizeof en);
    memset(next,-1,sizeof next);
}
bool cmp(string a,string b)
{
    if(a.size() == b.size() ) return a < b;
    return a.size() < b.size() ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        clr();
        int n;
        cin >> n;

        vector<string>vt;
        for(int i=0; i<n; i++)
        {
            string str;
            cin >> str;
            vt.push_back(str);
        }
        sort(vt.begin(),vt.end(),cmp);
        for(int i=0;i<n;i++)
        {
//            cout << vt[i] << endl;
            insert(vt[i]);
        }
        if(flag)
        {
            cout << "Case " << qq  << ": NO" << endl;
        }
        else
        {
            cout << "Case " << qq  << ": YES" << endl;
        }
    }

    return 0;
}
/*



*/
