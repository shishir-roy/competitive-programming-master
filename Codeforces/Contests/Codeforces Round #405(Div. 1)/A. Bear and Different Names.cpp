/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    vector<string>vt;
    for(char i='A';i<='Z';i++)
    {
        for(char j='a';j<='z';j++)
        {
            string t;
            t+=i;
            t+=j;
            vt.push_back(t);
        }
    }
    for(int i=0;i<n-k+1;i++)
    {
        string t;
        cin >> t;
        if(t=="NO")
        {
            vt[i+k-1]=vt[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}