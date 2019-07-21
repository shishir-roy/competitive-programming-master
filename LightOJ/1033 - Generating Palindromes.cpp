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
string str;
int dp[107][107];
int rec(int i,int j)
{
//    cout << str[i] << ' ' << str[j] << endl;
    if(i>=j)
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    if(str[i]==str[j]) ret=rec(i+1,j-1);
    else ret=1+ min(rec(i+1,j),rec(i,j-1));
    return ret;
}
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        cin >> str;
        memset(dp,-1,sizeof dp);
        pf("Case %d: %d\n",qq,rec(0,str.size()-1));
    }
    return 0;
}
/*

*/
