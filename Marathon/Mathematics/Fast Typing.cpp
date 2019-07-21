#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ara[60];
    string str;
    cin >> str;
    for(int i=0;i<26;i++)
        cin >> ara[i];
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        ans+=ara[str[i]-'a'];
    }
    cout << ans << endl;
    return 0;
}
