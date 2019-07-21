#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b;
    cin >> a >> b;
    long long int t=min(a,b),tt=1;
    for(int i=1;i<=t;i++)
    {
        tt*=i;
    }
    cout << tt ;
    return 0;
}
