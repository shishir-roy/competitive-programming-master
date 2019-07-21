#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mx=0;
    string str;
    while(cin >> str)
    {
        int t=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='A' and str[i]<='Z')
            {
                t++;
            }
        }
        mx=max(mx,t);
    }
    cout << mx;
    return 0;
}
