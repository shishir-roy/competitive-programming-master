#include<bits/stdc++.h>
using namespace std;
string str;
int sz;
void getbinary(long long int n)
{
    str.clear();
    while(n!=0)
    {
        str+=((n%2)+'0');
        n/=2;
    }
    reverse(str.begin(),str.end());
    sz=str.size();
}
long long int dp[40][3][3];
long long int rec(int ps,int flag,int prev)
{
    if(ps>=sz)
    {
        return 0;
    }
    long long int& ret=dp[ps][flag][prev];
    if(ret!=-1)return dp[ps][flag][prev];
    int d= flag==1 ? str[ps]-'0' : 1;
    ret=0;
    for(int i=0;i<=d;i++)
    {
        if(prev==1 && i==1)
            ret+=1;
        rec(ps+1,i<d?0:flag,i);
    }
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        long long int n;
        cin >> n;
        getbinary(n);
        memset(dp,-1,sizeof dp);
        long long int t=rec(0,1,0);
        cout << "Case " << qq << ": " << t << '\n';
    }
    return 0;
}
