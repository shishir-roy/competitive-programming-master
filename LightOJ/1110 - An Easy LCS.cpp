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
int dp[107][107],n,m,t;
vector<string>vt;
string sto[107][107];
int rec(int i,int j,string str)
{
    if(i>=m || j>=n)
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    if(str1[i]==str2[j])
    {
        sto[i][j]=sto[i-1][j-1]+str1[i];
        ret=1+rec(i+1,j+1,sto[i-1][j-1]+str1[i]);
    }
    else
    {
        ret=max(rec(i+1,j),rec(i,j+1));
    }
    return ret;
}
string ss;
void all(int i,int j)
{
    if(i>=m || j>=n)
    {
        if(ss.size()==t)
            vt.push_back(ss);
        return;
    }
    if(str1[i]==str2[j])
    {
        ss+=str1[i];
        all(i+1,j+1);
        ss.erase(ss.end()-1);
    }
    else if(dp[i+1][j]>dp[i][j+1])
    {
        all(i+1,j);
    }
    else if(dp[i+1][j]<dp[i][j+1])
    {
        all(i,j+1);
    }
    else
    {
        all(i+1,j);
        all(i,j+1);
    }
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
        m=str1.size(),n=str2.size();
        memset(dp,-1,sizeof dp);
        t=rec(0,0);
        if(t==0)
        {
            pf("Case %d: :(\n",qq);
        }
        else
        {
            vt.clear();
            ss.clear();
            all(0,0);
            sort(vt.begin(),vt.end());
            pf("Case %d: ",qq);
            cout << vt[0] << '\n';
        }
    }
    return 0;
}
/*

*/
