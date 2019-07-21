/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ara[10][10];
int n;
set<int>vt;
int flag[10];
void rec(int num)
{
    vt.insert(num);
	for(int k=0;k<n;k++)
    {
        if(flag[k]==0)
        {
            flag[k]=1;
            for(int t=0;t<6;t++)
            {
                rec(num*10+ara[k][t]);
            }
            flag[k]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin >> ara[i][j];
        }
    }

    memset(flag,0,sizeof flag);
    rec(0);
    int t=0;
    for(auto it=vt.begin(); it!=vt.end(); it++,t++)
    {
        if(*it!=t)
        {
            cout << max(0,t-1) << endl;
            return 0;
        }
    }
    return 0;
}
