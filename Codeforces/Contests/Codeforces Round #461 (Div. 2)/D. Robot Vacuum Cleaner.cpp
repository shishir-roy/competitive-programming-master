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

#define maxn 500007

ll hh[maxn];
int main()
{
//    cout << ("s"<"h") << endl;
    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    cin >>n;
    vector<string>vt;
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t;

        string a;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='s')a+='0';
            else a+='1';
        }
        vt.push_back(a);
    }
    sort(vt.begin(),vt.end());
    string t;
    for(int i=0;i<n;i++)
    {
        t+=vt[i];
    }
//    cout << t << endl;

    memset(hh,0,sizeof hh);
    ll cnt=0;


    for(int i=t.size()-1; i>=0; i--)
    {
        if(t[i]=='1')cnt++;
        hh[i]=cnt;
    }
    ll ans=0;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='0')
        {
            ans+=hh[i+1];
//            cout << i << " er jonno " << ans << endl;
        }
    }
    cout << ans;
    return 0;
}
/*
4
s
ssh
hs

hhhs


*/
