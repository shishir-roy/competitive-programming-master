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
    vector<int>nl,nr;
    for(int i=0; i<n; i++)
    {
        int l,r;
        cin >> l >> r;
        nl.push_back(l);
        nr.push_back(r);
    }
    sort(nl.begin(),nl.end());
    sort(nr.begin(),nr.end());
//    DB;
    int m;
    cin >> m;
    vector<int>ml,mr;
    for(int i=0; i<m; i++)
    {
        int l,r;
        cin >> l >> r;
        ml.push_back(l);
        mr.push_back(r);
    }
    sort(ml.begin(),ml.end());
    sort(mr.begin(),mr.end());
//    cout << ml[n-1] << nr[0] << endl;
    int d=max(ml[m-1]-nr[0],nl[n-1]-mr[0]);
    if(d<=0) cout <<0;
    else cout << d;
    return 0;
}
/*

*/
