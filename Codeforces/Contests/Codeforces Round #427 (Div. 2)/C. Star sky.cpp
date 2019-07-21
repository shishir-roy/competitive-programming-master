#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    int n,q,c;
    cin >> n >> q >> c;
    int ara[15][107][107];
    memset(ara,0,sizeof ara);
    for(int i=0;i<n;i++)
    {
        int x,y,s;
        cin >> x >> y >> s;
        ara[s][x][y]++;
    }
    for(int p=0;p<=c;p++)
    {
        for(int i=1;i<=101;i++)
        {
            for(int j=1;j<=101;j++)
            {
                ara[p][i][j]+=(ara[p][i-1][j]+ara[p][i][j-1]-ara[p][i-1][j-1]);
            }
        }
    }
    while(q--)
    {
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll ans=0;
        for(int p=0;p<=c;p++)
        {
            int temp=(p+t)%(c+1);
            int amt=ara[p][x2][y2]-ara[p][x1-1][y2]-ara[p][x2][y1-1]+ara[p][x1-1][y1-1];
            ans+=(temp*amt);
        }
        cout << ans << endl;
    }
    return 0;
}
