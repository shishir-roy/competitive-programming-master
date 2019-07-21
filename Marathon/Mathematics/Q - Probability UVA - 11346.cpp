#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define eps 1e-6
int main()
{
//    cout << log(2.71828) << endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        double a,b,s;
        cin >> a >> b >> s;
        double c=s/b;
        double d=a;
        double ar=a*b;
        double ans;
        if( s==0.0 ) ans=100.0;
//        else if(s>a*b) ans=0.0;
        else
        {
            double total=s* log(a*b/s) + b*c;
            ans=1-(total/ar);
            ans*=100.0;
        }
        cout << setprecision(6) << fixed << ans << "%" << endl;
    }

    return 0;
}
