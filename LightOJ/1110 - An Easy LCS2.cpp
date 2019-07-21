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
string str1,str2;
string dp[107][107];
int l,m;
string rec(int i,int j)
{
    if(i>=l || j>=m)
        return "";
    string &ret=dp[i][j];
    if(ret!="-1")
        return ret;
    if(str1[i]==str2[j])
    {
        ret=str1[i]+rec(i+1,j+1);
    }
    else
    {
        string temp=rec(i+1,j);
        string tem=rec(i,j+1);
        if(temp.size()>tem.size()) ret=temp;
        else if(temp.size()<tem.size()) ret=tem;
        else ret=min(temp,tem);
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
        cin >> str1 >> str2;
        l=str1.size(),m=str2.size();
        for(int i=0 ;i<107 ;i++ )
        {
            for(int j=0 ;j<107 ;j++ )
            {
                dp[i][j]="-1";
            }
        }
        string ans=rec(0,0);
        pf("Case %d: ",qq);
        if(ans.empty()) pf(":(\n");
        else cout << ans << '\n';
    }
    return 0;
}
/*

*/
