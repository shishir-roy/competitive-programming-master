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
    int n,m,t;
    cin >> n >> m;
    char ara[n+7];
    memset(ara,0,sizeof ara);
    string str;
    cin >> str;
    while(m--)
    {
        sf("%d",&t);
        int s=0;
        for(int i=t ;s<str.size() and i<=n ;i++,s++ )
        {
            ara[i]=str[s];
//            cout << ara[i] << endl;
        }
    }
    int cnt=0;
    for(int i=1 ;i<=n ;i++ )
    {
        cout << ara[i] ;
    }
    for(int i=1 ;i<=n ;i++ )
    {
        if(ara[i]==0){
            cout << i << endl;
            cnt++;
            }
    }
    ll ans=1;
    while(cnt--)
    {
        ans*=26;
        ans%=1000000007;
    }
    cout << ans ;
    return 0;
}
/*

*/
