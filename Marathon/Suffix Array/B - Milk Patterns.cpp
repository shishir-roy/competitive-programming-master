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
//#include<bits/stdc++.h>
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

int n,str[maxn],k;


struct entry{
    int nr[3],p;
}L[maxn];

int lcp[maxn],P[20][maxn];


bool cmp(entry a,entry b)
{
    return (a.nr[0] == b.nr[0]) ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
inline void SA()
{
    memset(P,-1,sizeof P);
    for(int i=0;i<n;i++)
    {
        P[0][i] = str[i];
    }

    int stp,cnt;
    for(stp = 1,cnt=1; cnt < n; stp++,cnt<<=1)
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
            P[stp][L[i].p] = i>0 && L[i-1].nr[0] == L[i].nr[0] && L[i-1].nr[1] == L[i].nr[1] ? P[stp][L[i-1].p] : i ;
        }
    }

//    for(int i=0;i<n;i++)
//    {
//        cout << L[i].p << " ";
//    }
//    cout << endl << endl;
    lcp[0] = 0;
    for(int i=1;i<n;i++)
    {
        int x = L[i-1].p;
        int y = L[i].p;
        lcp[i] = 0;
//        x=1,y=3;
//        int ret=0;
//        cout << x << " " << y << " --> ";
        for(int k=stp-1;k>=0;k--)
        {
            if( (P[k][x] == P[k][y]))
            {
//                ret += (1<<k);
                lcp[i] += (1<<k);
                x+=(1<<k);
                y+=(1<<k);
            }
        }
//        cout << lcp[i] << endl;
    }
}

int table[maxn][20];
int vt[maxn];
// AC code
void prepocess()
{
    for(int i=0;i<n;i++)
    {
        vt[i] = lcp[i];
    }
	for(int i=0;i<n;i++)
	{
		table[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=0;(i+(1<<j)-1)<n;i++)
		{
			if(vt[table[i][j-1]]<vt[table[i+(1<<(j-1))][j-1]])
			{
				table[i][j]=table[i][j-1];
			}
			else
			{
				table[i][j]=table[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int query(int l,int r)
{
	int e=r-l+1;
	int t=log2(e);
	return std::min( vt[table[l][t]], vt[table[r-(1<<t)+1][t]] );
}
int main()
{
    sf2(n,k);
    for(int i=0;i<n;i++)
    {
        sf1(str[i]);
    }
    SA();
    prepocess();
//    for(int i=0;i<n;i++)
//    {
//        cout << lcp[i] << " ";
//    }
//    cout << endl << endl;
    int mx = -1;
    for(int x=0;x+k-2<n;x++)
    {
        int t = query(x,x+k-2);
        mx=max(mx,t);
    }
    cout << mx << endl;
    return 0;
}
/*



*/
