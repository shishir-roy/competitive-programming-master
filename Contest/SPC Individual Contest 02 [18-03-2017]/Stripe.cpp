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
    int n;
    cin >> n;
    int ara[n+7];
    int sums[n+7];
    ara[0]=0;
    sums[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >> ara[i];
        sums[i]=sums[i-1]+ara[i];
    }
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(sums[i]==sums[n]-sums[i])
        {
//            cout << sums[i] << endl;
//            cout << i << endl;
//            DB;
            cnt++;
        }
    }
    cout << cnt ;
    return 0;
}
/*

*/
