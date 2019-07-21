#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 100000
string str;
int k,j;
bool ok(int i)
{
    string temp=str.substr(i,j);
    string t=temp;
    reverse(temp.begin(),temp.end());
    if(t==temp)
        return 1;
    return 0;
}
int main()
{
    cin >> str;
    cin >> k;
    int l=str.size();
    if(l%k==0)
    {
        j=l/k;
        for(int i=0 ;i<l ;i+=j )
        {
            if(!ok(i))
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
        return 0;
    }
    else cout << "NO";
    return 0;
}
/*
fff
2

*/
