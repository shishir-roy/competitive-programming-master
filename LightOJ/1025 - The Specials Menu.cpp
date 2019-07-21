#include<bits/stdc++.h>
using namespace std;
string str;
long long int dp[70][70];
long long int rec(int i,int j)
{
    if(i>j || j<i ) return 0;
    long long int& ret=dp[i][j];
    if(ret!=-1)
        return ret;
    if(str[i]==str[j])
    {
        ret=1+ rec(i+1,j-1) + rec(i+1,j) + rec(i,j-1) - rec(i+1,j-1);
    }
    else
    {
        ret=rec(i+1,j) + rec(i,j-1) - rec(i+1,j-1);
    }
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cin >>str;
        memset(dp,-1,sizeof dp);
        cout << "Case " << qq << ": " << rec(0,str.size()-1) << '\n';
    }
    return 0;
}
