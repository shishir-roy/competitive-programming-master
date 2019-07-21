#include<bits/stdc++.h>
using namespace std;
vector<int>vt;
int dp[107][107];
int rec(int i,int j)
{
    if(i>j) return 0;
    int& ret=dp[i][j];
    if(ret!=-1) return ret;
    int p=0,diff=INT_MIN;
    for(int k=i;k<=j;k++)
    {
        p+=vt[k];
        diff=max(diff,p-rec(k+1,j));
    }
    p=0;
    for(int k=j;k>=i;k--)
    {
        p+=vt[k];
        diff=max(diff,p-rec(i,k-1));
    }
    return ret=diff;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        cin >> n;
        vt.clear();
        for(int i=0;i<n;i++)
        {
            int t;
            cin >> t;
            vt.push_back(t);
        }
        memset(dp,-1,sizeof dp);
        cout << "Case " << qq << ": " << rec(0,n-1) << '\n';
    }
    return 0;
}
