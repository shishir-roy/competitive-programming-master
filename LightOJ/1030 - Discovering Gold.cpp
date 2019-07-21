#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int n;
double ara[107];

double  dp[107];
double rec(int ps)
{
    if(ps==n-1)
    {
        return ara[n-1];
    }
    double& ret=dp[ps];
    if(ret>-1.0)
        return ret;
    ret=0.0;
    int i=1;
    int f=0;
    for(i=1;i<=6;i++)
    {
        if(i+ps<n)
        {
            ret+=( (ara[ps]+rec(ps+i))/6.0 );
        }
        else
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        int t=max(0,6-i+1);
        ret=( 6.0*ret )/ (6-t);
    }
    return ret;
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
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> ara[i];

        for(int i=0;i<105;i++)
            dp[i]=-100.0;
        double temp=rec(0);
        cout << "Case " << qq << ": "  << setprecision(10) << fixed << temp << endl;
    }

    return 0;
}
