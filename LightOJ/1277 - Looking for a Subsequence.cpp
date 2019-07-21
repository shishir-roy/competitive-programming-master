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
#define pcase(x)              printf("Case %d:\n",x)
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

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    sf1(tc);
    for(int qq=1; qq<=tc; qq++)
    {
        int n,q;
        sf2(n,q);
        int ara[n+7];
        for(int i=0; i<n; i++)
        {
            sf1(ara[i]);
        }
        pcase(qq);
        while(q--)
        {
            int m;
            sf1(m);

            set<int>st,ans;
            set<int>::iterator it;
            for(int i=n-1; i>=0; i--)
            {
                st.insert(ara[i]);
//                cout << "insert hocce " << ara[i] << endl;


                cout << endl;
                it = st.find(ara[i]);
                if(it != st.begin() )
                {
                    it=st.begin();
//                    cout << "erase hocce " << *it << endl;
                    st.erase(it);
                }
                cout << "set contains " << endl;
                for(int x : st)
                {
                    cout << x << " ";
                }
                if(st.size()>m)
                {
                    it = st.end();
                    it--;
                    st.erase(it);
                }

                if(st.size()==m)
                {
                    ans.clear();
                    ans = st;
                }

            }

            cout << "lis ---> " << endl;
            for(int x : st)
            {
                cout << x << " ";
            }
            cout << endl;
            if(ans.size()==m)
            {
                it = ans.begin();
                pf("%d",*it);
                it++;
                for(; it != ans.end(); it++)
                {
                    pf(" %d",*it);
                }
                pf("\n");
            }
            else
            {
                pf("Impossible\n");
            }
        }
    }
    return 0;
}
/*

3
8 5
8 7 5 6 5 1 2 7
3
*/
