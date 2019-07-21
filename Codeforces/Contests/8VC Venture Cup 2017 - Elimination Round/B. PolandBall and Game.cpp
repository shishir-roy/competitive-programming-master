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
    int p,e;
    cin >> p >> e;
    string pw[p+7],ew[e+7];
    for(int i=0 ;i<p ;i++ )
    {
        cin >> pw[i];
    }
    int cnt=0;
    for(int i=0 ;i<e ;i++ )
    {
        cin >> ew[i];
        for(int j=0 ;j<p ;j++ )
        {
            if(pw[j]==ew[i])
            {
                cnt++;
            }
        }
    }
    if(cnt%2==1)
    {
        p++;
    }
    if(p>e)
    {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}
/*

*/
