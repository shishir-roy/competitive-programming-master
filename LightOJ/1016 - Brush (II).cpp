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
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	int n,w;
    	cin >> n >> w;
    	std::vector<int>vt;
    	for(int i=0;i<n;i++)
    	{
    		int a,b;
    		cin >> a >> b;
    		vt.push_back(b);
    	}
    	sort(vt.begin(),vt.end());
    	int d=vt[0]+w, cnt=1;
    	for(int i=0;i<n;i++)
    	{
    		if(vt[i]>d)
    		{
    			cnt++;
    			d=vt[i]+w;
    		}
    	}
    	cout << "Case " << qq << ": " << cnt << endl;
    }
    return 0;
}