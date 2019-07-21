
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        int n;
        scanf("%d",&n);
        ll x[n+7],y[n+7];
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld",&x[i],&y[i]);
        }
        vector< pair<ll,ll> > vt;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll mx=x[i]+x[j], my=y[i]+y[j];
                vt.push_back(make_pair(mx,my));
            }
        }
        sort(vt.begin(),vt.end());
        ll ans=0,cnt=1;
//        cout << "vt size " << vt.size() << endl;
        for(int i=1;i<vt.size();i++)
        {
//            cout << vt[i].first << " " << vt[i].second << "   --->> " << vt[i-1].first << " " << vt[i-1].second << endl;
            if(vt[i]==vt[i-1])
            {
                cnt++;
            }
            else
            {
                ans+=( cnt*(cnt-1)/2 );
                cnt=1;
            }
        }
        ans+=cnt*(cnt-1)/2;
        cout << "Case " << qq << ": " << ans << endl;
    }
    return 0;
}
