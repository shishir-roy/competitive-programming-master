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
    for(int qq=1 ; qq<=tc ; qq++ )
    {
        ll p,l;
        sf("%lld %lld",&p,&l);
        vector<int>vt;
        int s=sqrt(p);
        int t=p-l;
        for(int i=1 ; i<=s ; i++ )
        {
            if(t%i==0)
            {
                if(t/i>l)
                {
                    vt.push_back(t/i);
                }
                if(i>l && t/i!=i)
                {
                    vt.push_back(i);
                }
            }
        }
        sort(vt.begin(),vt.end());
        if(vt.empty())
        {
            pf("Case %d: impossible",qq);
        }
        else
        {
            pf("Case %d: %d",qq,vt[0]);
            for(int i=1 ; i<vt.size() ; i++ )
            {
                pf(" %d",vt[i]);
            }
        }
        pf("\n");
    }
    return 0;
}
/*
2147483648
*/
