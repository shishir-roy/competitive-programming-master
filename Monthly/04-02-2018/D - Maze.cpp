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
int n,m,k;
bool ok(int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<m) return 1;
    else return 0;
}
int fy[] = {1,-1,0,0};
int fx[] = {0,0,1,-1};
int flag[507][507];
string str[507];
void dfs(int x,int y)
{
    if(k>0)
    {
        str[x][y] = 'X';
        k--;
    }
    else
    {
        return ;
    }
    flag[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        int tx = fx[i] + x;
        int ty = fy[i] + y;
        if(ok(tx,ty) and str[tx][ty]=='.' and flag[tx][ty]==0)
        {
            dfs(tx,ty);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> str[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j] == '.')
            {
                dfs(i,j);
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}
/*



*/
