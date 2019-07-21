#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

double dp[maxn];

double rec(int n)
{
    if(n==1)
        return 0;
    double& ret=dp[n];
    if(ret > -1.0) return ret;

//    cout << "ites fine " << endl;
    int sq=sqrt(n)-2;
    while(sq*sq<n)
        sq++;
    int cnt=2;
    for(int i=2;i<sq;i++)
    {
        if(n%i==0)
        {
            cnt+=2;
        }
    }
    if(sq*sq==n)cnt++;

    ret=0;
    for(int i=2;i<sq;i++)
    {
        if(n%i==0)
        {
            ret+=( 1+rec(i) )/(double)cnt;
            ret+=( 1+rec(n/i) )/(double)cnt;
        }
    }

    if(sq*sq==n)ret+=( 1+rec(sq) )/(double)cnt;

    ret+=( 1+rec(1) )/(double)cnt;

    ret+=1.0/cnt;
    ret=(ret*cnt)/(double)(cnt-1);
    return ret;
}
int main()
{
    for(int i=0;i<maxn;i++)
        dp[i]=-100.0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int t;
        cin >> t;
        cout << "Case " << qq << ": "  << setprecision(10) << fixed << rec(t) << endl;
    }

    return 0;
}
