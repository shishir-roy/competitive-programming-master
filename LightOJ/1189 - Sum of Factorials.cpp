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
    vector<ll>vt;
    vt.push_back(0);
    vt.push_back(1);
    for(int i=2 ;i<=20 ;i++ )
    {
        vt.push_back(vt[i-1]*i);
    }
    int tc;
    sf("%d",&tc);
    for(int qq=1 ;qq<=tc ;qq++ )
    {
        ll num;
        sf("%lld",&num);
        vector<int>res;
        int f=0;
        while(num>0)
        {
            vector<ll>::iterator it;
            it=lower_bound(vt.begin(),vt.end(),num);
            if(vt[it-vt.begin()]!=num)it--;
            if(!res.empty() and res.back()==it-vt.begin())
            {
                if(num==2)
                {
                    res.push_back(0);
                    res.push_back(1);
                    break;
                }
                pf("Case %d: impossible\n",qq);
                f=1;
                break;
            }
            res.push_back(it-vt.begin());
            num-=vt[it-vt.begin()];
        }
        if(f)continue;
        sort(res.begin(),res.end());
        pf("Case %d: %d!",qq,res[0]);
        for(int i=1 ;i<res.size() ;i++ )
        {
            pf("+%d!",res[i]);
        }
        pf("\n");
    }
    return 0;
}
/*
9
9

*/
