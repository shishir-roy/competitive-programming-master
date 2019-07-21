#include<bits/stdc++.h>
using namespace std;
long long int egcd(long long int a,long long int b,long long int& x,long long int& y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long int x1,y1;
    long long int g=egcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
/// returning number of solutions
/// form of the equation ax + by = c
long long int linear_diaphontic(long long int a,long long int b,long long int c,long long int xmin, long long int xmax,long long int ymin,long long int ymax)
{
    if(a==0 and b==0 and c==0)
    {
        return -1;
    }
    else if(a==0 and b==0 and c!=0)
    {
        return 0;
    }
    else if(a==0 and (b==c))
    {
        return 1;
    }
    else if(a==0 and (b!=c))
    {
        return 0;
    }
    else if(b==0 and (a==c))
    {
        return 1;
    }
    else if(b==0 and (a!=c))
    {
        return 0;
    }
    long long int xg,yg; /// egcd theke pawya equation form :: a xg + b yg = g;
    long long int g=egcd(abs(a),abs(b),xg,yg);
    cout << g << " " << xg << " " << yg << endl;
    if(c%g)
    {
        return 0;
    }
    else
    {
        long long int x0=xg*(c/g);
        long long int y0=yg*(c/g);
        if(a<0) x0*=(-1);
        if(b<0) y0*=(-1);
        cout << x0 << " " << y0 << endl;
        cout << g << endl;
        long long int p,q,r,s;
        if(x0<0)
        {
            x0*=(-1);
            xmin+=x0;
            xmax+=x0;
            p=xmin/abs(b/g);
            q=xmax/abs(b/g);
            if(xmin-(xmin/abs(b/g))*abs(b/g))p+=1;
        }
        else
        {
            xmin-=x0;
            xmax-=x0;
            p=xmin/abs(b/g);
            q=xmax/abs(b/g);
            if(xmin-(xmin/abs(b/g))*abs(b/g))p+=1;
        }
//        cout << p << " " << q << endl;
        if(y0<0)
        {
            y0*=(-1);
            ymin+=y0;
            ymax+=y0;
            r=ymin/abs(a/g);
            s=ymax/abs(a/g);
            if(ymin-(ymin/abs(a/g))*abs(a/g))r+=1;
        }
        else
        {
            ymin-=y0;
            ymax-=y0;
            r=ceil(ymin/abs(a/g));
            s=ymax/abs(a/g);
            if(ymin-(ymin/abs(a/g))*abs(a/g))r+=1;
        }
//        cout << r << " " << s << endl;
        r*=(-1);
        s*=(-1);
        swap(r,s);
        long long int u=max(p,r);
        long long int v=min(q,s);
        return abs(u-v)+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        long long int a,b,c,xmin,xmax,ymin,ymax;
        cin >> a >> b >> c >> xmin >> xmax >> ymin >> ymax ;
        long long int t=linear_diaphontic(a,b,-c,xmin,xmax,ymin,ymax);
//        cout << "-----> " << t << endl;
        cout << "Case " << qq << ": " << t << endl;
    }
    return 0;
}
/*
5
-2 -2 -48 -12 10 -29 -27
*/
