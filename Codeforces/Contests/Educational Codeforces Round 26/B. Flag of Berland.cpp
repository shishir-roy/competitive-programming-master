#include<bits/stdc++.h>
using namespace std;
vector<string>vt;
int n,m;
int chk_row()
{
    if(n%3!=0) return 0;
    int a=n/3;
    char ch=vt[0][0];
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    ch=vt[a][0];
    for(int i=a; i<a+a; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    ch=vt[a+a][0];
    for(int i=a+a; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    return 1;
}
int chk_col()
{
    if(m%3!=0) return 0;
    int a=m/3;
    char ch=vt[0][0];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<a; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    ch=vt[0][a];
    for(int i=0; i<n; i++)
    {
        for(int j=a; j<a+a; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    ch=vt[0][a+a];
    for(int i=0; i<n; i++)
    {
        for(int j=a+a; j<m; j++)
        {
            if(vt[i][j]!=ch)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string t;
        cin >> t;
        vt.push_back(t);
    }
    if(chk_row()||chk_col())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
