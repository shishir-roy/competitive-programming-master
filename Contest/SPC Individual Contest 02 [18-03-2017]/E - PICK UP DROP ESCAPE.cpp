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
int dp[25][25];
int rec(int ps,int cnt)
{
    if(ps>=n)
    {
        if(cnt==k) return 0;
        return
    }
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    int a=5^1^3;
    cout << a << endl;
    cin >> tc;
    while(tc--)
    {
        int n,k;
        cin >> n >>k;
        int ara[n+8];
        for(int i=0; i<n; i++)
        {
            cin >> ara[i];
        }
        memset(dp,-1,sizeof dp);
        int ans=rec(0,0);
    }
    return 0;
}
/*
2
5 3
1 2 3 4 5
*/
