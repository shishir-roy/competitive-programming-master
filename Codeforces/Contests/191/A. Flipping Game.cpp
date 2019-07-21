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
    vector<int>ara(n+7);
//    int ara[n+7];
    for(int i=0; i<n; i++)
        cin >> ara[i];

    int ans=0;
//    for(int i=0; i<n; i++)
//    {
//        if(ara[i]==1)
//        {
//            ans++;
//        }
//    }

    for(int l=0; l<n; l++)
    {
        for(int r=l; r<n; r++)
        {
            vector<int>vt;
            vt=ara;
            for(int i=l; i<=r; i++)
            {
                if(vt[i]==1)
                {
                    vt[i]=0;
                }
                else vt[i]=1;
            }

            int cnt=0;
            for(int i=0; i<n; i++)
            {
                if(vt[i]==1)
                {
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
    }

    cout << ans << endl;
    return 0;
}
