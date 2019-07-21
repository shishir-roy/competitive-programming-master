#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    string str;
    cin >> str;

    string t;
    for(int i=0;i<10;i++)
    {
        t+=str;
    }
    int f=1,ans=0,id=0;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='1')
        {
            f=0;
            break;
        }
    }
    if(f)
    {
        cout << n*k << endl;
        return 0;
    }
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='1' and f==0)
        {
            ans=max(ans,i-id);
            id=9999;
            f=1;
        }
        if(t[i]=='0' and f==1)
        {
            f=0;
            id=i;
        }
    }

//    if(t.back()=='0' and f==0)
//    {
//        if(t.size()-id>ans)
//        {
//            ans=t.size()-id;
//        }
//    }
    cout << ans << endl;
    return 0;
}
