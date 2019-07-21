#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
int main()
{
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        int n;
        vector<int>vt;
        sf("%d",&n);
        while(n>0)
        {
            vt.push_back(n%2);
            n/=2;
        }
        vt.push_back(0);
        reverse(vt.begin(),vt.end());
        next_permutation(vt.begin(),vt.end());
        ll ans=0,ps=0;
        for(int i=vt.size()-1 ;i>=0 ;i-- )
        {
            if(vt[i])
            {
                ans|=(1<<ps);
            }
            ps++;
        }
        pf("Case %d: %lld\n",qq,ans);
    }
    return 0;
}
/*

*/
