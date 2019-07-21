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
    int n;
    unordered_map<string,bool>mp;
    cin >> n;
    vector<string>vt,ans;
    for(int i=0;i<n;i++)
    {
    	string t;
    	cin >> t;
    	vt.push_back(t);
    }
    reverse(vt.begin(),vt.end());
    for(auto it:vt)
    {
    	if(mp[it]==0)
    	{
    		ans.push_back(it);
    		mp[it]=1;
    	}
    }
    for(auto it:ans)
    	cout << it << endl;
    return 0;
}