#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ara[n+7];
    for(int i=0;i<n;i++)
    {
        cin >> ara[i];
    }
    ll ans=0;

    ll flag[n+7];
    memset(flag,0,sizeof flag);
    for(int i=n-1;i>=0;i--)
    {
        if(ara[i]==0)
        {
            flag[i]++;
        }
        flag[i]+=flag[i+1];
    }
    for(int i=0;i<n;i++)
    {
        if(ara[i]==1)
        {
            ans+=flag[i+1];
        }
    }

//    int rr[n+7];
//    memset(rr,0,sizeof rr);
//    for(int i=0;i<n;i++)
//    {
//        if(ara[i]==1)
//        {
//            rr[i]++;
//        }
//        if(i !=0 )
//        {
//            rr[i]+=rr[i-1];
//        }
//    }
//
//    int ans1=0;
//    for(int i=n-1;i>=0;i--)
//    {
//        if(ara[i]==0)
//        {
//            ans1+=rr[i];
//        }
//    }
//    cout << min(ans,ans1) << endl;
    cout << ans << endl;
    return 0;
}
