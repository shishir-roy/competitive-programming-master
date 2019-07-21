#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        ll x,y;
        cin >> x >> y;
        ll mult=x*y;
        ll a=pow(mult,1.0/3.0)-2;
        while(a*a*a<mult)
        {
            a++;
        }
        if(a*a*a==x*y and x%a==0 and y%a==0 )
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
    return 0;
}
