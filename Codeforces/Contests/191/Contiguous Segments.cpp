#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector< pair<int,int> > vt;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        vt.push_back({x,y});
    }
    sort(vt.begin(),vt.end());
    if(n%2==1)
    {
        int l,r;
        l=r=n/2;
        l--;
        r++;
        int ans=0;
        while(l>=0)
        {
            int d=vt[l+1].first-vt[l].second;
            ans+=d;
            vt[l].first+=d;
            vt[l].second+=d;

            d=vt[r].first-vt[r-1].second;
            ans+=d;
            vt[r].first-=d;
            vt[r].second-=d;
            l--,r++;
        }
        cout << ans << endl;
    }
    else
    {
        vector< pair<int,int> >temp(vt.begin(),vt.end());
        int l,r;
        l=r=n/2;
        l--;
        r++;
//        cout << l << " " << r << endl;
        int ans1=0;
        while(l>0)
        {
            int d=vt[l+1].first-vt[l].second;
            ans1+=d;
            vt[l].first+=d;
            vt[l].second+=d;

            d=vt[r].first-vt[r-1].second;
            ans1+=d;
            vt[r].first-=d;
            vt[r].second-=d;
            l--,r++;
        }
        int d=vt[l+1].first-vt[l].second;
        ans1+=d;
        vt[l].first+=d;
        vt[l].second+=d;
//        cout << "ans1 " << ans1 << endl;

        l=r=n/2 - 1;
        l--;
        r++;
//        cout << l << " " << r << endl;
        int ans2=0;
        while(l>=0)
        {
            int d=temp[l+1].first-temp[l].second;
            ans2+=d;
            temp[l].first+=d;
            temp[l].second+=d;

            d=temp[r].first-temp[r-1].second;
            ans2+=d;
            temp[r].first-=d;
            temp[r].second-=d;
            l--,r++;
        }
        d=temp[r].first-temp[r-1].second;
        ans2+=d;
        temp[r].first-=d;
        temp[r].second-=d;

//        cout << "ans2 " << ans2 << endl;
        cout << min(ans1,ans2) << endl;
    }
    return 0;
}
