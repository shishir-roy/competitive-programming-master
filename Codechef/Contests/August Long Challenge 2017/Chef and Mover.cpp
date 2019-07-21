/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n,d;
        cin >> n >> d;
        ll sum=0;
        int ara[n+7];
        for(int i=0; i<n; i++)
        {
            cin >> ara[i];
            sum+=ara[i];
        }
        ll avg=0,f=1;
        if(sum%n==0)
        {
            avg=sum/n;
        }
        else
        {
            cout << -1 << '\n';
            continue;
        }
        ll ans=0;
        for(int i=0; i<d; i++)
        {
            ll s=0;
            ll cnt=0;
            vector< pair<int,int> >vt;
            for(int j=i; j<n; j+=d)
            {
                vt.push_back({ara[j],j});
                s+=ara[j];
                cnt++;
            }
            ll a=0;
            if(s%cnt==0)
            {
                a=s/cnt;
            }
            else
            {
                f=0;
                break;
            }
            if(a!=avg)
            {
                f=0;
                break;
            }
            int cc=0;
            int x=0,y=vt.size()-1;
            /* cout << "y " << y << endl;
             cout << vt[2].first << endl;*/
            sort(vt.begin(),vt.end());
            while(cc<cnt)
            {
                if(vt[x].first!=a && vt[y].first!=a && vt[x].first!=vt[y].first)
                {
                    /*cout <<vt[x].first << " " << vt[y].first << endl;*/
                    int t=abs(vt[y].second-vt[x].second)/d;
                    /*cout << "index " << t << endl;*/
                    int com=min( abs(vt[x].first-a),abs(vt[y].first-a) );
                    /*cout << "prev " << ans << endl;*/
                    ans+=(t*com);
                    /*cout << "after " << ans << " " << t*com << endl;*/
                    if(vt[x].first<a)
                    {
                        vt[x].first+=com;
                        vt[y].first-=com;
                    }
                    else
                    {
                        vt[x].first-=com;
                        vt[y].first+=com;
                    }
                    /*cout <<vt[x].first << " " << vt[y].first << endl;*/
                }
                /*cout << endl;*/
                if(vt[x].first==a)
                {
                    cc++;
                    x++;
                }
                if(vt[y].first==a)
                {
                    cc++;
                    y--;
                }
            }
          /*  cout << " ans " << ans << endl;*/
        }
        /*cout << " wtf " << ans << endl;*/
        if(f==0)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ans << '\n';
        }
        /*cout << " ##### " << endl;*/
    }
    return 0;
}
