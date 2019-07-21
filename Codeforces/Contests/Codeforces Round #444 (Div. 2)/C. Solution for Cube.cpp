/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector<int,int> >vt[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pre=-1,t;
    for(int i=0;i<24;i++)
    {
        cin >> t;
        if(pre!=t)
        {
            cnt=0;
            t=pre;
        }
        else
        {
            cnt++;
        }
        if(cnt)
    }
    return 0;
}
