#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
bool check(int n,int ps)
{
    return (bool)(n&(1<<ps));
}
int seti(int n,int ps)
{
    return ( n|=(1<<ps) );
}
int dp[1<<16];
int health[18];
char str[18][18];
int n;
int cnt=0;
int rec(int mask)
{
    int t = __builtin_popcount(mask);
    if(t == n)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int ans=inf;
    for(int i=0; i<n; i++)
    {
        if(!((mask>>i)&1))
        {
            ans=min(ans,health[i]+rec(mask|(1<<i)));
            for(int j=0; j<n; j++)
            {
                if(((mask>>j)&1))
                {
                    int d=str[j][i]-'0';
                    if(d==0)
                        continue;
                    ans=min(ans,(health[i]+d-1)/d+rec(mask|(1<<i)));
                }
            }
        }
    }
    return dp[mask]=ans;
}

int main()
{
//   freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);

//    const clock_t begin_time = clock();
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> health[i];
        }
        for(int i=0; i<n; i++)
        {
            sf("%s",str[i]);
        }
        memset(dp,-1,sizeof dp);
        int ans=rec(0);
        cout << "Case " << qq << ": " << ans << '\n';
    }
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

