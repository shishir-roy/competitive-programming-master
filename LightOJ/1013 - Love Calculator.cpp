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
string a,b;
int dp[35][35];
int l,m,siz;
int lcs(int i,int j)
{
    if(i>=l|| j>=m) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    if(a[i]==b[j]) ret=1+lcs(i+1,j+1);
    else
    {
        ret=max(lcs(i+1,j),lcs(i,j+1));
    }
    return ret;
}
ll dpp[65][65][65];
ll rec(int i,int j,int cnt)
{
    if(i==l && j==m)
    {
        if(cnt==siz) return 1;
        return 0;
    }
    else if(i==l)
    {
        if(siz==cnt+m-j) return 1;
        return 0;
    }
    else if(j==m)
    {
        if(siz==cnt+l-i) return 1;
        return 0;
    }
    ll &ret=dpp[i][j][cnt];
    if(ret!=-1) return ret;
    if(a[i]==b[j]) ret=rec(i+1,j+1,cnt+1);
    else
    {
        ret=rec(i+1,j,cnt+1)+rec(i,j+1,cnt+1);
    }
    return ret;

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        cin >> a >>b;
        l=a.size(),m=b.size();
        memset(dp,-1,sizeof dp);
        siz=l+m-lcs(0,0);
        memset(dpp,-1,sizeof dpp);
        ll ans=rec(0,0,0);
        pf("Case %d: %d %lld\n",qq,siz,ans);
    }
    return 0;
}
/*

*/
