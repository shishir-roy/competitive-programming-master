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

#define maxn 581827
struct data
{
    ll tk,loan;
};
data tree[5*maxn];
void updt(int id,int l,int r,int ps,int val)
{
    if(l==r)
    {
        if(val>0)
        {
            tree[id].tk = val;
        }
        else
        {
            tree[id].loan = - val;
        }
        return ;
    }
    int mid = (l+r)/2;
    if(ps<=mid)
    {
        updt(id*2,l,mid,ps,val);
    }
    else
    {
        updt(id*2+1,mid+1,r,ps,val);
    }

    tree[id].tk = tree[id*2].tk + tree[id*2+1].tk;
    if(tree[id*2+1].loan <= tree[id*2].tk)
    {
        tree[id].tk -= tree[id*2+1].loan;
        tree[id].loan = 0;
    }
    else
    {
        tree[id*2+1].loan -= tree[id].tk;
        tree[id].tk = 0;
    }
    tree[id].loan = tree[id*2+1].loan ;
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    sf1(n);
    int c,date,month,hour,minute;
    while(n--)
    {
        sf("%d %d.%d %d:%d", &c, &date, &month, &hour, &minute);

        ll mp = ( ( month*31 + date )*24 + hour) * 60 + minute;
        updt(1,1,maxn-3,mp,c);
        int t = tree[1].loan*-1;
        cout << t << endl;
    }
    return 0;
}
/*



*/
