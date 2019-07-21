/*
ID:shishir10
LANG:C++
TASK:transform
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> rotat(vector<string>temp)
{
    vector<string> tt=temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tt[i][j]=temp[j][n-i-1];
        }
    }
    return tt;
}
vector<string> reff(vector<string>temp)
{
    vector<string> tt;
    for(int i=0;i<n;i++)
    {
        reverse(temp[i].begin(),temp[i].end());
        tt.push_back( temp[i] );
    }
    return tt;
}
int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin >> n;
    vector<string>before,after;
//    cout << "n " << n << endl;
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t;
        before.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t;
        after.push_back(t);
    }
    if(before==rotat(after))
    {
        cout << 1 << '\n';
    }
    else if(before==rotat(rotat(after)))
    {
        cout << 2 << '\n';
    }
    else if(before==rotat(rotat(rotat(after))))
    {
        cout << 3 << '\n';
    }
    else if(before==reff(after))
    {
        cout << 4 << '\n';
    }
    else if( before== reff(rotat(after)) or before== reff(rotat(rotat(after))) or before==reff(rotat(rotat(rotat(after)))) )
    {
        cout << 5 << '\n';
    }
    else if(before==after)
    {
        cout << 6 << '\n';
    }
    else
    {
        cout << 7 << '\n';
    }
    return 0;
}
