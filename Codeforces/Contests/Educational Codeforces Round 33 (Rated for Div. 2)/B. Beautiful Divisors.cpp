#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll pre[100];
    for(int i=1;i<100;i++)
    {
        pre[i]=( (1<<i)-1 ) * ( 1<<(i-1) );
    }
    int n;
    cin >> n;
    ll mx=0;
    for(int i=1;i<100 && pre[i]<=n;i++)
    {
        if(n%pre[i]==0)
        {
            mx=max(mx,pre[i]);
        }
    }
    cout << mx << endl;
    return 0;
}
