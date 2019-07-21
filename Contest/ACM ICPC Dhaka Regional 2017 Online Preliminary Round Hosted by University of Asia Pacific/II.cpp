#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define LL long long
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define D(x) cout << #x " is " << x << endl

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<string> VS;

const int INF = 2000000009;
const int MX = 100005;
const double EPS = 1e-9;
const int MOD = 1000000007;

/*******************************************************/

int power(int b,int p)
{
    if (b==0) return b;
    int ret = 1;
    for (int i = 0;i<p;i++)
        ret*=b;
    return ret;
}
int main()
{
    //std::ios_base:ync_with_stdio(false);

	int tc,cn = 0;
    scanf("%d",&tc);
    while (tc--)
    {
        char a[MX],b[MX];
        scanf("%s%s",a,b);
        int r = 0;
        int la = strlen(a);
        if (a[0]=='0'){
            printf("0\n");
            continue;
        }
        for (int i = 0;i<la;i++)
        {
            r+=a[i]-'0';
            r%=9;
        }
        if (r==0) r = 9;
        int lb = strlen(b);
        int temp = 1;
        int ans = 1;
        for (int i = lb-1;i>=0;i--)
        {
            ans*=(power(temp,b[i]-'0'));
            ans%=9;
            temp= power(temp,10)%9;
        }
        if(ans==0) ans = 9;
        printf("%d\n",ans);
    }

	return 0;
}
