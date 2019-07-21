#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,mod=10056;

ll table[1007][1007];
void nCr()
{
    for(int i=0;i<1007;i++)
    {
        table[i][0],table[i][i]=1;
        table[i][1]=i;
        for(int j=2;j<i;j++)
        {
            table[i][j]=(table[i-1][j]+table[i-1][j-1])%mod;
        }
    }
}

ll dp[1007];
ll rec(int rem)
{
    if(rem==0) return 1;
    if(rem<0 ) return 0;
    ll& ret=dp[rem];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=n;i++)
    {
        ret+=( table[rem][i]*rec(rem-i) ) %mod;
        ret%=mod;
    }
    return ret;
}

int main()
{
    nCr();
    int tc;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    for(int qq=1;qq<=tc;qq++)
    {
        scanf("%d",&n);
        int ret=rec(n)%mod;
        printf("Case %d: %d\n",qq,ret);
    }
    return 0;
}
