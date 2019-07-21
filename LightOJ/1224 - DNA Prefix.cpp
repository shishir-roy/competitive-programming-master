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

#define maxn 50001*51

int nex[4][maxn];
int mark[maxn],sz=0;
int mx = -1;

void insert(string str)
{
    int v = 0;
    for(int i=0; i<str.size(); i++)
    {
        int ch;
        if(str[i] == 'A')
        {
            ch = 0;
        }
        else if(str[i] == 'C')
        {
            ch = 1;
        }
        else if(str[i] == 'G')
        {
            ch = 2;
        }
        else
        {
            ch = 3 ;
        }
        if(nex[ch][v] == -1)
        {
            nex[ch][v] = ++sz;
        }
        v = nex[ch][v];
        mark[v]++;
        mx = max(mx,mark[v]*(i+1) );

    }
}

void clr()
{
    memset(mark,0,sizeof mark);
    memset(nex,-1,sizeof nex);
    sz = 0;
    mx = 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        cin >> n;

        vector<string>vt;
        for(int i=0; i<n; i++)
        {
            string t;
            cin >> t;
            vt.push_back(t);
        }
        clr();

        for(int i=0; i<n; i++)
        {
            insert(vt[i]);
        }
        cout << "Case " << qq << ": " << mx << endl;
    }
    return 0;
}
/*
3
4
CGCGCCGCGCGCGC GCGCGC
CGCGCCGCGCGCGC TC


*/
