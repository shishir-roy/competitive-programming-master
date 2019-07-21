#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x;
    cin >> x;
    if(x==1)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 ;
        return 0;
    }
    vector< pair<long long int,long long int> > vt;
    long long int n=1,m=x,pre=0,lim=x;
    while(n<lim)
    {
        long long int den=n*(n+1)/2;
        long long int nu=(x+pre);
        long long int m=nu/den;
        lim=min(lim,m);
//       cout << n << " ---> " << m << endl;
        if(nu%den==0)
        {
            if(n!=m)
                vt.push_back({n,m});
            vt.push_back({m,n});
        }
        pre=den+pre;
        n++;
    }
    sort(vt.begin(),vt.end());
    cout << vt.size() << '\n';
    for(int i=0; i<vt.size(); i++)
        cout << vt[i].first << " " << vt[i].second << '\n';
    return 0;
}
