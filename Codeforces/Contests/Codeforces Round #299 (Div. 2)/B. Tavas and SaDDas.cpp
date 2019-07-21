#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647
#define eps 1e -10
#define maxn 1000000007
#define mod 100000007
vector<ll>vt;
void init(ll num)
{
    if(num>maxn)
        return;
    vt.push_back(num);
    init(num*10+4);
    init(num*10+7);
}
int main()
{
    init(0);
    sort(vt.begin(),vt.end());
    ll n;
    cin >>n;
    for(int i=1;i<vt.size();i++)
    {
        if(vt[i]==n){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
/*


*/
