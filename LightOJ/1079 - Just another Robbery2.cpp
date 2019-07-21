#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int tak[1007],sum=0,n;
double dp[10007],cau[1007];
void pre()
{
    for(int i=1;i<=sum;i++)
    {
        dp[i]=1.0;
    }
    dp[0]=0.0;
    for(int i=0;i<n;i++)
    {
        for(int j=sum;j>=tak[i];j--)
        {
            dp[j]=min(dp[j], dp[j-tak[i]] + (1.0-dp[j-tak[i]])*cau[i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        double gp;
        cin >> gp >> n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> tak[i] >> cau[i];
            sum+=tak[i];
        }
        pre();
        int ans=0;
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]<gp)
            {
                ans=i;
                break;
            }
        }
        cout << "Case " << qq << ": "  << ans << endl;
    }
    return 0;
}
