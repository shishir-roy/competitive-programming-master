#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
double gp, cau[107];
int igp,icau[107];
int tak[107],n;

int dp[107][10007];
double rec(int ps,int amt,int p)
{
    if(ps>=n) return 0;
    int& ret=dp[ps][amt];
    if(ret!=-1) return ret;
    int p1=0,p2=0;
    if(p+(100-p)*icau[ps] <= igp)
    {
        p1=tak[ps]+rec(ps+1,amt+tak[ps],p+(100-p)*icau[ps]);
    }
    p2=rec(ps+1,amt,p);
    return ret=max(p1,p2);
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
        cin >> gp >> n;
//        gp-=.0001;
        igp=gp*100;
        cout << "igp " << igp << endl;
        for(int i=0;i<n;i++)
        {
            cin >> tak[i] >> cau[i];
            icau[i]=cau[i]*1000;
            cout << cau[i] << " fine " << icau[i] << endl;
//            cout << icau[i] << endl;
        }
        memset(dp,-1,sizeof dp);
        int ans=rec(0,0,0);
        cout << "Case " << qq << ": "  << ans << endl;
    }
    return 0;
}
/*
5
0.27 6
10 0.86
5 0.11
6 0.61
2 0.89
9 0.27
4 0.81
*/
