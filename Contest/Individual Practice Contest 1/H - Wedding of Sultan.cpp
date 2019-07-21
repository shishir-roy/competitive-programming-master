#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>gr[100];
string str;
void mak()
{
    for(int i=0;i<100;i++) gr[i].clear();
    stack<char>st;
    st.push(str[0]);
    for(int i=1;i<str.size();i++)
    {
        char ch=st.top();
        if(ch==str[i])
        {
            st.pop();
        }
        else
        {
//            cout << ch << " --> " << str[i] << endl;
            st.push(str[i]);
            gr[ch-'A'].push_back(str[i]);
            gr[str[i]-'A'].push_back(ch-'A');
        }
    }
    for(int i=0;i<27;i++)
    {
        if(!gr[i].empty())
        {
            char ch=i+'A';
            cout << ch << " = " << gr[i].size() << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        cin >> str;
        cout << "Case " << qq << endl;
        mak();
    }
    return 0;
}
