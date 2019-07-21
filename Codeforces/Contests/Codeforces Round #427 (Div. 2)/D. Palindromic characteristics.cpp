#include<bits/stdc++.h>
using namespace std;
int ans[5050];
int dp[5050][5050];
string str;
int main()
{
    cin >> str;
    int n=str.size();
    for(int len=1; len<=n; len++)
    {
        for(int l=0; l+len-1<n; l++)
        {
            int r=l+len-1;
            if(len==1)
            {
                dp[l][r]=1;
            }
            else if(len==2 and str[l]==str[r])
            {
                dp[l][r]=2;
            }
            else if(str[l]!=str[r] or dp[l+1][r-1]==0)
            {
                continue;
            }
            dp[l][r]=1;
            long long int mid=(l+r)/2;
            if(len%2==1)
            {
                dp[l][r]=1+dp[l][mid-1];
            }
            else
            {
                dp[l][r]=1+dp[l][mid];
            }
        }
    }
    for(int len=1; len<=n; len++)
    {
        for(int l=0; l+len-1<n; l++)
        {
            int r=l+len-1;
            ans[dp[l][r]]++;
        }
    }
//    for(int i=0; i<n; i++)
//        cout << ans[i+1] << " ";
    for(int i=n; i>=0; i--)
    {
        ans[i]+=ans[i+1];
    }
    for(int i=0; i<n; i++)
        cout << ans[i+1] << " ";
    return 0;
}
