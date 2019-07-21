#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
double dp[607][607][7];

double rec(int r,int b,int p)
{
    if(r+b==1)
    {
        if(b==1)
            return 1.0;
        if(r==1)
            return 0.0;
    }
    double& ret=dp[r][b][p];
    if(ret > -0.1) return ret;

    ret=0.0;
    if(p==1)
    {
        if(r>0)
        {
            ret+=( rec(r-1,b,2)*(double)r )/(double)(r+b);
        }
        if(b>0)
        {
            ret+=( rec(r,b-1,2)*(double)b )/(double)(r+b);
        }
        return ret;
    }

    if(b>0)
        ret+= rec(r,b-1,1);
    return ret;
}
inline void seti()
{
    for(int i=0; i<507; i++)
    {
        for(int j=0; j<507; j++)
        {
            for(int k=0; k<5; k++)
            {
                dp[i][j][k]=-1.0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    seti();
    for(int qq=1; qq<=tc; qq++)
    {
        int r,b;
        cin >> r >> b;
        double ans=rec(r,b,1);
        cout << "Case " << qq << ": " << setprecision(10) << fixed << ans << '\n';
    }
    return 0;
}
