#include<bits/stdc++.h>
using namespace std;
#define ll long long int
pair<int,int>vt[207];
pair<int,pair<int,int> > dp[207][207];
pair<int,int> five_two(ll a)
{
    ll cnt=0;
    while(a%2==0)
    {
        cnt++;
        a/=2;
    }
    ll cntt=0;
    while(a%5==0)
    {
        cntt++;
        a/=5;
    }
    return {cnt,cntt};
}
ll ans=0;
ll n,k;
void rec(int ps,int cnt)
{
    if(cnt==k)
    {
        ans=max(ans,min(dp[ps][cnt].first,dp[ps][cnt].second));
    }
    if(ps>=n)
    {
        return {0,{0,0}};
    }
    pair<int,pair<int,int> >& ret=dp[ps][cnt];
    if(ret!={0,{0,0}})
        return ret;
    pair<int,pair<int,int> > temp1=rec(ps+1,cnt+1)
}
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        ll t;
        cin >> t;
        vt.push_back(five_two(t));
    }
}
