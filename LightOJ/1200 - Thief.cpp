#include<bits/stdc++.h>
using namespace std;
int p[107],w[107];
int dp[107][10007];
int n;
int rec(int ps,int sum)
{
    if(ps>=n)
    {
        return 0;
    }
    int& ret=dp[ps][sum];
    if(ret!=-1) return ret;
    if(sum>=w[ps])
        ret=rec(ps,sum-w[ps])+p[ps];
    ret=max(ret,rec(ps+1,sum));
    return ret;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
       int tw,s=0;
       scanf("%d %d",&n,&tw);
       for(int i=0;i<n;i++)
       {
           int t=0;
           scanf("%d %d %d",&p[i],&t,&w[i]);
           s+=(t*w[i]);
       }
       int cap=tw-s;
       if(cap<0)
       {
           printf("Case %d: Impossible\n",qq);
       }
       else if(cap==0)
       {
           printf("Case %d: 0\n",qq);
       }
       else
       {
           /*cout << "cap " << cap << endl;*/
           memset(dp,-1,sizeof dp);
           int ans=rec(0,cap);
           printf("Case %d: %d\n",qq,ans );
       }
    }
    return 0;
}