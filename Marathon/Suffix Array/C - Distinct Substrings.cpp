#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <stdio.h>      /* printf */
#include <math.h>       /* log2 */
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

struct entry{
    int nr[3],p;
};
bool cmp(const entry &a,const entry &b)
{
    return ( a.nr[0] == b.nr[0] ) ? (a.nr[1]<b.nr[1] ? 1 : 0) : (a.nr[0]<b.nr[0] ? 1 : 0);
}
int lcp[maxn];
string str;
inline void SAp()
{
    cout << "celeron " << str << endl;
    cout << "yeah " << endl;
    int n = str.size();
    int P[20][maxn];
    for(int i=0;i<n;i++)
    {
        P[0][i] = str[i] - 'A';
    }
    int stp=1;
    entry L[maxn];
    cout << "fine " << endl;
    for(int cnt=1; cnt<n; stp++,cnt<<=1)
    {
        for(int i=0;i<n;i++)
        {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<n ? P[stp-1][i+cnt] : -1;
            L[i].p = i;
        }
        sort(L,L+n,cmp);
        for(int i=0;i<n;i++)
        {
            P[stp][L[i].p] = i>0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        int x = L[i].p;
        int y = L[i+1].p;
        lcp[i] = 0;
        cout << x << " " << y ;
        for(int k=stp-1;k>=0;k--)
        {
            if(P[k][x] == P[k][y])
            {
                lcp[i]+=(1<<k);
                x+=(1<<k);
                y+=(1<<k);
            }
        }
        cout << " --> " << lcp[i] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cout << "its ok" << endl;
        cin >> str;
        cout << str << " after" << endl;
        cout << "calling" << endl;
        SAp();
    }
    return 0;
}
/*



*/
