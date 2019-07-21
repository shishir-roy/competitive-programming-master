//#include <cstdio>
//#include <sstream>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <stack>
//#include <list>
//#include <iostream>
//#include <fstream>
//#include <numeric>
//#include <string>
//#include <vector>
//#include <cstring>
//#include <map>
//#include <iterator>
//#include <stdio.h>      /* printf */
//#include <math.h>       /* log2 */
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
#define maxn 1007

struct entry
{
    int nr[3],p;
} L[maxn];
int P[20][maxn];
int lcp[maxn];
inline bool cmp(const entry &a,const entry &b)
{
    return (a.nr[0] == b.nr[0]) ? (a.nr[1]<b.nr[1] ? 1 : 0) : (a.nr[0]<b.nr[0] ? 1 : 0);
}
inline void SA(string str)
{
    int n = str.size();
    int an = n/2;
    memset(P,-1,sizeof P);
    for(int i=0; i<n; i++)
    {
        P[0][i] = str[i]-'@';
    }

    int stp =1;
    for(int cnt=1; cnt<n; cnt<<=1,stp++)
    {
        for(int i=0; i<n; i++)
        {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<n ? P[stp-1][i+cnt] : -1;
            L[i].p = i;
        }
        sort(L,L+n,cmp);
        for(int i=0; i<n; i++)
        {
            P[stp][L[i].p] = i>0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
        }
    }
    cout << " duck --> " << P[stp-1][6] << endl;
//    cout << P[stp-1][1] << endl;
//    cout << P[stp-1][2] << endl;
//    cout << P[stp-1][3] << endl;

    memset(lcp,0,sizeof lcp);
    int mx = -1,id=0;

    for(int i=1; i<n; i++)
    {
        int x = L[i-1].p;
        int y = L[i].p;

        int tx = x, ty=y;

        for(int k=stp-1; k>=0; k--)
        {
            if(P[k][tx] == P[k][ty])
            {
                lcp[i] += (1<<k);
                tx += (1<<k);
                ty += (1<<k);
            }
        }

        cout << x << " " << y << " er lcp " << lcp[i] << endl;
        if(lcp[i]>mx)
        {
            int p = lcp[i];
            int a = min(x,y);
            int b = max(x,y);

            cout << "updating ---> " << a << " " << b << " " << mx << endl;
            if( b == n-(a-1+p)-1 )
            {
                id = x;
                mx = lcp[i];
            }
        }

    }
    string ans;
    ans = str.substr(id,mx);
    cout << ans << endl;
//    cout << mx << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    string t;
    t=str;
    reverse(t.begin(),t.end());
//    str+='#';
    str+=t;
    cout << str  << " " << str.size() << endl;
    for(int i=0;i<str.size();i++)
    {
        cout << i << " --> " << str[i] << endl;
    }
    SA(str);
    return 0;
}
/*
abcSOMETEXTcba


*/
