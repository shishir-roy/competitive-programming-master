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
#define maxn 10007
int ara[maxn];
int id(int r)
{
//    cout << ara[r] << ' ' << r << endl;
    if(ara[r]==r)
        return r;
    ara[r]=id(ara[r]);
    return ara[r];
}
int main()
{
    int n;
    cin >> n;
    for(int i=1 ;i<=n ;i++ )
    {
        ara[i]=i;
    }
    int t;
    for(int i=1 ;i<=n ;i++ )
    {
        sf("%d",&t);
        int x=id(i),y=id(t);
        if(x!=y)
        {
            ara[x]=y;
        }
    }
//    id(1);
//    DB;
    for(int i=1 ;i<=n ;i++ )
    {
        id(i);
    }
    set<int>st;
    for(int i=1 ;i<=n ;i++ )
    {
        st.insert(ara[i]);
    }
    cout << st.size() ;
    return 0;
}
/*

*/
