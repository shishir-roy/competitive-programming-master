#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
int node[maxn];
bool ok(int i,int j)
{
    return node[i]+node[j]==3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        int t;
        cin >> t;
        node[t]=1;
    }
    for(int i=0;i<k;i++)
    {
        int t;
        cin >> t;
        node[t]=2;
    }

    int ans1=0;
    for(int i=1;i<=n;i++)
    {
        if(ok(i,i+1))
        {
            i++;
            ans1++;
        }
    }

    int ans2=ok(1,n);
    for(int i=n-1;i>2;i--)
    {
        if(ok(i,i-1))
        {
            i--;
            ans2++;
        }
    }
    int t=max(ans1,ans2);
    cout << t+(k-t)*2 << endl;
    return 0;
}
