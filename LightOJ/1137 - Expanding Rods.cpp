#include<bits/stdc++.h>
using namespace std;
#define Pi 2*acos(0.0)
double bs(double l,double lprime)
{
    double lo=0,hi=10000,t=-1.0;
    while(fabs(lo-hi)>0.00000001)
    {
        double r=(lo+hi)/2.0;
        double angle=lprime/r;
        double temp=2.0*r*sin(angle/2.0);
        if(fabs(temp-l)<0.00000001)
        {
            t=angle;
            break;
        }
        else if(temp<l)
        {
            lo=r;
        }
        else hi=r;
    }
    cout << "angle " << t << endl;
    return t;
}
int main()
{
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        double l,n,c;
        cin >> l >> n >> c;
        double lprime= (1+n*c)*l;
        cout << lprime << endl;
        double centerr_angle=bs(l,lprime);
        double center_angle_degree=180.0*centerr_angle/Pi;
        double alph=(360.0-center_angle_degree)/2.0;
        cout << (l/2.0)/(tan(alph)) << endl;
    }
}
