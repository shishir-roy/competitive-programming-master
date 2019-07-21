#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int dp[57][57][57];
int rec(int i,int j,int k)
{
//    cout << "call ing " << endl;
    if(i==0 || j==0 || k==0)
        return 0;
    int& ret=dp[i][j][k];
    if(ret!=-1) return ret;
    if(a[i-1]==b[j-1] and a[i-1]==c[k-1])
    {
//        cout << "###" << endl;
//        cout << a[i] << endl;
        ret=1+rec(i-1,j-1,k-1);
    }
    else
    {
        ret=0;
        ret=max(ret,rec(i-1,j,k));
        ret=max(ret,rec(i,j-1,k));
        ret=max(ret,rec(i,j,k-1));
        ret=max(ret,rec(i-1,j-1,k));
        ret=max(ret,rec(i,j-1,k-1));
        ret=max(ret,rec(i-1,j,k-1));
    }
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        cin >> a >> b >> c;
        memset(dp,-1,sizeof dp);
        int t=rec(a.size(),b.size(),c.size());
        cout << "Case " << qq << ": " << t << '\n';
    }
    return 0;
}
