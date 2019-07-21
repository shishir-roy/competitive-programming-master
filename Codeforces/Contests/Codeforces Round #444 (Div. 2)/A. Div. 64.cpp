#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int cnt=0,ok=0;
    for(int i=str.size()-1;i>=0;i--)
    {
        if(str[i]=='0')
        {
            cnt++;
        }
        if(cnt>=6 and str[i]=='1')
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout << "yes";
    else cout << "no";
    return 0;
}
