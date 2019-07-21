#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a=1,b=2;
    int f=1;
    for(int i=0; i<n; i++)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            if(a==1 && b==2)
            {
                b=3;
            }
            else if(a==1 && b==3)
            {
                b=2;
            }
            else if(a==2 && b==1)
            {
                a=3;
            }
            else if(a==3 && b==1)
            {
                a=2;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(t==2)
        {
            if(a==2 && b==1)
            {
                b=3;
            }
            else if(a==2 && b==3)
            {
                b=1;
            }
            else if(a==1 && b==2)
            {
                a=3;
            }
            else if(a==3 && b==2)
            {
                a=1;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(t==3)
        {
            if(a==3 && b==1)
            {
                b=2;
            }
            else if(a==3 && b==2)
            {
                b=1;
            }
            else if(a==1 && b==3)
            {
                a=2;
            }
            else if(a==2 && b==3)
            {
                a=1;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
