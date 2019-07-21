#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string n;
    cin >> k >> n;
    int t=0;
    for(int i=0; i<n.size(); i++)
    {
        t+=(n[i]-'0');
    }
    if(k<=t)
    {
        cout << 0;
    }
    else
    {
//        cout << "###" << endl;
        sort(n.begin(),n.end());
        int i;
//        cout << t << endl;
        for(i=0; i<n.size(); i++)
        {
            t+=(9-n[i]+'0');
            if(t>=k)
            {
                cout << i+1;
                return 0;
            }
//            cout << t << endl;
        }
//        cout << t << endl;
        if(t>=k)
        {
            cout << i+1;
            return 0;
        }
    }
    return 0;
}
