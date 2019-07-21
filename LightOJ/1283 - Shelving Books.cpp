#include<bits/stdc++.h>
using namespace std;
int ara[107],n;
int dp[107][107][107];
int rec(int ps,int l,int r)
{
    if(ps>n)
        return 0;
    int& ret=dp[ps][l][r];
    if(ret!=-1) return ret;
    ret=INT_MIN;
    if(ara[ps]>=ara[l] && ara[ps]<=ara[r])
    {
        ret=max(ret,1+rec(ps+1,ps,r));
        ret=max(ret,1+rec(ps+1,l,ps));
    }
    ret=max(ret,rec(ps+1,l,r));
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> ara[i];
        }
        memset(dp,-1,sizeof dp);
        ara[0]=-1,ara[n+1]=1<<30;
        int t=rec(1,0,n+1);
        cout << "Case " << qq << ": " << t << endl;
    }
    return 0;
}
