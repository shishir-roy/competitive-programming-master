#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    long long int g=0;
    for(int i=0;i<str.size();i++)
    {
        g*=10;
        g+=(str[i]-'0');
    }
//    cout << "its g " << g << endl;
    int t=(str[0]-'0'+1);
    int tt=0;
    for(int i=1;i<str.size();i++)
    {
        if(str[i]!='0')
        {
            tt=1;
        }
        t*=10;
    }
//    cout << " its t " << t << endl;
    cout << t-g << '\n';
    return 0;
}
