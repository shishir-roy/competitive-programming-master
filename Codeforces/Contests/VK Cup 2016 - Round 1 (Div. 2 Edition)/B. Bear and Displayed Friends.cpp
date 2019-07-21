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
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k,q;
    cin >> n >> k >> q;
    int t[n+7];
    for(int i=0 ;i<n ;i++ )
    {
        sf("%d",&t[i]);
    }
    int typ,a;
    vector<int>vt;
    while(q--)
    {
        sf("%d %d",&typ,&a);
        if(typ==1)
        {
            vt.push_back(t[a-1]);
            sort(vt.begin(),vt.end(),cmp);
            if(vt.size()>k) vt.resize(k);
            for(auto& it :vt )
            {
                cout << it << endl;
            }
        }
        else if(binary_search(vt.begin(),vt.end(),t[a-1]))
        {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}
/*

*/
