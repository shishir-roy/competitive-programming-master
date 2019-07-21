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
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	vt.push_back(t);
    }
    vector<int>temp;
    sort(temp.begin(),temp.end());
    vector<int>ans[100007];
    int a=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
    	int t=vt[i],cnt=0;
    	int pos=lower_bound(vt.begin(),vt.end(),t)-vt.begin()+1;
    	for(;j<n;j++)
    	{
    		
    		ans[a++].push_back()
    	}
    }
    return 0;
}