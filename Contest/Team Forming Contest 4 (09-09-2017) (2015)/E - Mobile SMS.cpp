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
    string ara[]={" ",".,\?\"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	string ans;
    	int n;
    	cin >> n;
    	int key[n+7],no[n+7];
    	for(int i=0;i<n;i++)
    	{
    		cin >> key[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		int t;
    		cin >> t;
    		ans+=ara[key[i]][t-1];
    	}
    	cout << ans << endl;
    }
    return 0;
}