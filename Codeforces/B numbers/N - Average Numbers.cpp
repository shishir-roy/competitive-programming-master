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
    cin >> n;
    vector<int>vt;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
    	int t;
    	cin >> t;
    	vt.push_back(t);
    	sum+=t;
    }
    vector<int>ans;
    for(int i=0;i<vt.size();i++)
    {
    	ll t=sum-vt[i];
    	ll avg=t/(n-1);
    	if(vt[i]==avg and t%(n-1)==0 )
    	{
    		ans.push_back(i+1);
    	}
    }
    if(ans.empty())
    	cout << 0 ;
    else
    {
    	cout << ans.size() << endl;
    	for(int i : ans)
    		cout << i << " ";
    }
    return 0;
}