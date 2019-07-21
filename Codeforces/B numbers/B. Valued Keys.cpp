#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x,z,y;
    cin >> x >> y;
    for(int i=0;i<x.size();i++)
    {
        if(y[i]>x[i])
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << y << '\n';
    return 0;
}
