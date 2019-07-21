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
    int n,k;
    cin  >> n >> k;
    vector<int>vt;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	vt.push_back(t);
    }
    ll sum=0;
    int mx=INT_MIN,st=0;
    for(int i=0;i<vt.size();i++)
    {
    	sum+=vt[i];
    	while(sum>k)
    	{
    		sum-=vt[st];
    		st++;
    	}
    	mx=max(mx,i-st+1);
    }
    cout << mx << endl;
    return 0;
}