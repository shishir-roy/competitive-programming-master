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
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    sf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        int n,m;
        sf("%d %d",&n,&m);
        vector<ll>vt;
        for(int i=0;i<n;i++)
        {
            int t;
            sf("%d",&t);
            vt.push_back(t);
        }
//        DB;
        while(m--)
        {
            char ch;
            cin >> ch;
            if(ch=='S')
            {
                int t;
                sf("%d",&t);
                for(int i=0;i<n;i++)
                {
                    vt[i]+=t;
                }
            }
            else if(ch=='M')
            {
                int t;
                sf("%d",&t);
                for(int i=0;i<n;i++)
                {
                    vt[i]*=t;
                }
            }
            else if(ch=='D')
            {
                int t;
                sf("%d",&t);
                for(int i=0;i<n;i++)
                {
                    vt[i]/=t;
                }
            }
            else if(ch=='R')
            {
                reverse(vt.begin(),vt.end());
            }
            else if(ch=='P')
            {
                int a,b;
                sf("%d %d",&a,&b);
                swap(vt[a],vt[b]);
            }
        }
        pf("Case %d:\n",qq);
        pf("%lld",vt[0]);
        for(int i=1 ;i<n ;i++ )
        {
            pf(" %lld",vt[i]);
        }
        pf("\n");
    }
    return 0;
}
/*

*/
