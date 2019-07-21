#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

ll dp[50];
int rec(int ps)
{
    if(ps==1)
        return 1;
    ll& ret =dp[ps];
    if(ret != -1)
        return ret;
    ret=1;
    for(int i=1;i<=ps-2;i++)
    {
        ret+=rec(i);
    }
    return ret;
}


void solve(int n)
{
    string str;
    int l=-1;
    for(int i=0;i<46;i++)
    {
//        cout << n << " *** " << dp[i] << endl;
        if(dp[i]>=n)
        {
            l=i;
            break;
        }
    }

    cout << "expected length of the string " << l << endl;
    for(int i=0;i<l and str.size()<=l ;i++)
    {
        for(int j=0;j<46;j++)
        {
            if(dp[j]>=n)
            {
                str+="10";
                break;
            }
            else
            {
                n-=dp[i];
            }
        }
    }
    cout << str << endl;
}
int main()
{
    memset(dp,-1,sizeof dp);
//    cout << rec(45) << endl;
    dp[0]=0;
    for(int i=1;i<46;i++)
    {
        dp[i]=rec(i);
    }

    for(int i=1;i<46;i++)
    {
        dp[i]+=dp[i-1];
    }
    cout << dp[2] << endl;


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
