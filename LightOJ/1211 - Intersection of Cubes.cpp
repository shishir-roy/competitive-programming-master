#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        cin >> n;
        int x1[n+7],y1[n+7],z1[n+7],x2[n+7],y2[n+7],z2[n+7];
        for(int i=0;i<n;i++)
        {
            cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
        }
        int xh=0,xl=2000,yh=0,yl=2000,zh=0,zl=2000;
        for(int i=0;i<n;i++)
        {
            xl=min(xl,x2[i]);
            xh=max(xh,x1[i]);
            yl=min(yl,y2[i]);
            yh=max(yh,y1[i]);
            zl=min(zl,z2[i]);
            zh=max(zh,z1[i]);
        }
//        cout << xl << " " << xh << endl;
        long long int ans= (xl-xh) * (yl-yh) * (zl-zh);
        if(ans<0) ans=0;
        cout << "Case " << qq << ": " << ans << '\n';
    }
    return 0;
}
