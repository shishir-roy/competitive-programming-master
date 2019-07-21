#include<bits/stdc++.h>
using namespace std;
int func(int a,int b,int x1,int y1,int x2,int y2)
{
    if(x1>a) return 0;
    if(y1>b) return 0;
    int aa1=a-x1;
    int bb1=b-y1;
    if(aa1>=x2 and b>=y2) return x1*y1+x2*y2;
    if(a>=x2 and bb1>=y2) return x1*y1+x2*y2;
    return 0;
}
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector< pair<int,int> > vt;
    for(int i=0;i<n;i++)
    {
        int p,q;
        cin >> p >> q;
        vt.push_back({p,q});
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            mx=max(mx,func(a,b,vt[i].first,vt[i].second,vt[j].first,vt[j].second) );
            mx=max(mx,func(a,b,vt[i].second,vt[i].first,vt[j].first,vt[j].second) );
            mx=max(mx,func(a,b,vt[i].second,vt[i].first,vt[j].second,vt[j].first) );
            mx=max(mx,func(a,b,vt[i].first,vt[i].second,vt[j].second,vt[j].first) );
//            cout << func(a,b,vt[i],vt[j]) << endl;
        }
    }
    cout << mx ;
    return 0;
}
