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
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        int n,m;
        sf("%d %d",&n,&m);
        if(n==1)
        {
            pf("Case %d: %d\n",qq,m);
        }
        else if(m==1)
        {
            pf("Case %d: %d\n",qq,n);
        }
        else if(n==2)
        {
            int ans=4*(m/4);
            if(m%4==1)
                ans+=2;
            else if(m%4==2 or m%4==3)
                ans+=4;
            pf("Case %d: %d\n",qq,ans);
        }
        else if(m==2)
        {
            int ans=4*(n/4);
            if(n%4==1)
                ans+=2;
            else if(n%4==2 or n%4==3)
                ans+=4;
            pf("Case %d: %d\n",qq,ans);
        }
        else
        {
            int ans=n*m;
            int t=ans/2;
            if(ans%2==1)
                t++;
            pf("Case %d: %d\n",qq,t );
        }
    }
    return 0;
}
/*

*/
