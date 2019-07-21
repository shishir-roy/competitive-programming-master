#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ghor[n+7],tim[n+7];
    ghor[0]=1;
    tim[1]=0;
    set<int>st;
    st.insert(1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        if(tim[ghor[x]]==x)
        {
            ghor[x]=i;
            tim[i]=ghor[x];
        }
        else
        {
            st.insert(st.size()+1);
            ghor[x]=i;
            tim[i]=st.size();
        }
    }
    cout << st.size() << endl;

    return 0;
}
