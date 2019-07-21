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
    	int n;
    	cin >> n;
    	vector<int>ara,temp;
    	for(int i=0;i<n;i++)
    	{
    		int t;
    		cin >> t;
    		ara.push_back(t);
    	}
    	temp=ara;
    	sort(temp.begin(),temp.end());
    	int cnt=0;
    	for(int x=0,y=0;y<n;)
    	{
    		if(temp[x]==ara[y])
    		{
    			x++,y++;
    		}
    		else
    		{
    			y++;
    			cnt++;
    		}
    	}
    	/*cout << cnt << endl;*/
    	cout << "Case " << qq << ": " << cnt << endl;

    }
    return 0;
}