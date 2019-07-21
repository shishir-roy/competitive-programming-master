#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
#define mod                   1000000007
#define inf                   INT_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 100007
bool cmp(pii a,pii b)
{
    if(a.fs == b.fs)
    {
        return a.sc>b.sc;
    }
    return a.fs<b.fs;
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    map<pii,int>mp;
    vector<pii>vt;
    int n;
    sf1(n);
    for(int i=1; i<=n; i++)
    {
        int x,y;
        sf2(x,y);
        vt.push_back(make_pair(x,y));
        mp[make_pair(x,y)] = i;
    }

    map<pii,int>qmp;
    int q;
    sf1(q);
    for(int i=0; i<q; i++)
    {
        int t;
        sf1(t);
        vt.push_back(make_pair(t,0));
        qmp[make_pair(t,0)] = i;
    }
    sort(vt.begin(),vt.end(),cmp);

    int ans[q+7];
    stack<pii>st;
    for(int i=0; i<vt.size(); i++)
    {
        pii temp = vt[i];
        if(temp.sc==0)
        {
            if(st.empty())
            {
                ans[qmp[temp]] = -1;
//                cout << ans[qmp[temp]] << " print " << endl;
                continue;
            }
            while( !st.empty() and (st.top().fs>temp.fs || st.top().sc<temp.fs) )
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[qmp[temp]] = -1;
//                cout << ans[qmp[temp]] << " print " << endl;
                continue;
            }
            ans[qmp[temp]] = mp[st.top()];

//            cout << ans[qmp[temp]] << " print " << endl;
        }
        else
        {
            st.push(temp);
        }
    }
    for(int i=0; i<q; i++)
    {
        pf1(ans[i]);
    }

    return 0;
}
/*

3
2 10
2 3
5 7
11
1
2
3
4
5
6
7
8
9
10
11

*/
