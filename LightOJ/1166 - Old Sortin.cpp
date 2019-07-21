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
    	vector<int>vt;
    	for(int i=0;i<n;i++)
    	{
    		int t;
    		cin >> t;
    		vt.push_back(t);
    	}
 		vector<int>temp=vt;
 		sort(temp.begin(),temp.end());
 		int cnt=0;
 		for(int i=0;i<n;i++)
 		{
 			if(temp[i]!=vt[i])
 			{
 				for(int j=i;j<n;j++)
 				{
 					if(vt[j]==temp[i])
 					{
 						swap(vt[j],vt[i]);
 						cnt++;
 					}
 				}
 			}
 		}
 		cout << "Case "  << qq << ": " << cnt << endl;   
    }
    return 0;
}