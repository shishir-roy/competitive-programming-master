#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c;
    cin >> a >> b >> c;
    cout << min(min(a,b)*2+c*2,min(2*a+2*b,a+b+c));
    return 0;
}
