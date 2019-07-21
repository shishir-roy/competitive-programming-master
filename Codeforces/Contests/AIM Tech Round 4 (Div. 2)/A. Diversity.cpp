/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int t;
    cin >> str >> t;
    set<char>st;
    for(auto it : str)
    {
    	st.insert(it);
    }
    int k=t-st.size();
    if(st.size()>=t)
    {
    	cout << 0;
    }
    else if(t>26 || t>str.size())
    {
    	cout << "impossible" << endl;
    }
    else
    {
    	cout << k;
    }
    return 0;
}