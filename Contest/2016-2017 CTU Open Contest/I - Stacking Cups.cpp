#include<bits/stdc++.h>
using namespace std;
int f(string str)
{
    int t=1,ans=0;
    for(int i=str.size()-1;i>=0;i--)
    {
        ans+=(str[i]-'0')*t;
        t*=10;
    }
    return ans;
}
int main()
{
    int n;
    while(cin >>n)
    {
        vector< pair<int,string> >vt;
        for(int i=0;i<n;i++)
        {
            string s,t;
            cin >> s >> t;
            if(s[0]>='a' && s[0]<='z')
            {
                vt.push_back({f(t),s});
            }
            else
            {
                vt.push_back({f(s)/2,t});
            }
        }
        sort(vt.begin(),vt.end());
        for(auto it:vt)
        {
            cout << it.second << endl;
        }
    }
    return 0;
}
