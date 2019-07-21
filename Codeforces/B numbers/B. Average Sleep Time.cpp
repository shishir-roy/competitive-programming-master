#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int>vt(n+7);
    for(int i=0;i<n;i++)
        cin >> vt[i];
    unsigned long long int t=0,cur=0;
    for(int x=0,y=0;y<n;y++)
    {
        if(y-x+1<k)
        {
            t+=vt[y];
        }
        else
        {
            if(cur==0)
            {
                t+=vt[y];
                cur=t;
                continue;
            }
            cur=cur+vt[y]-vt[x];
            t+=cur;
            x++;
        }
    }
    double ans=(double)t/(double)(n-k+1);
    cout << setprecision(10) << ans << endl;
    return 0;
}
