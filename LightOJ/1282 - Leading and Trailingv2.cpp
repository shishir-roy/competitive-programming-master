#include<bits/stdc++.h>
using namespace std;
long long int bgmd(long long int b,long long int p)
{
    long long int ans=1;
    while(p>0)
    {
        if(p&1)
        {
            ans%=1000;
            ans*=b;
            ans%=1000;
        }
        b=(b*b)%1000;
        p>>=1;
    }
    return ans;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        double n,k;
        cin >> n >> k;
        int trail=bgmd(n,k);
        double t=k*log(n)/log(10);
        int tt=floor(t);
        double a=pow(10,t-tt);
//        cout << setprecision(10) << a << endl;
        int b=(a+.00001)*100;
        int c=(a-.00001)*100;
        if(b>=1000)
            b/=10;
//        cout << b << " " << c << endl;
        printf("Case %d: %02d %03d\n",qq,b,trail);
    }
    return 0;
}
