#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int ara[n+7];
    set<int>st,t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
        st.insert(ara[i]);
    }
//    cout << st.size() << endl;
    for(int i=n-1;i>=0;i--)
    {
        if(t.size()==st.size()-1 and t.find(ara[i])==t.end())
        {
            cout << ara[i] << endl;
            return 0;
        }
        t.insert(ara[i]);
    }
    return 0;
}
