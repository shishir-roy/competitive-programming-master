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
    	vector<string>vt;
    	for(int i=0;i<5;i++)
    	{
    		string t;
    		cin >> t;
    		vt.push_back(t);
    	}
    	int f=0,c=0;
    	for(int i=0;i<5;i++)
    	{
    		f=0;
    		for(int j=0;j<5;j++)
    		{
    			if( (vt[i][j]=='|' or vt[i][j]=='<') and f==0 )
    			{
    				/*cout << i << " " << j << endl;*/
    				f=1;
    			}
    			else if( (vt[i][j]=='>' or vt[i][j]=='|') and f==1)
    			{
    				/*cout << i << " " << j << endl;*/
    				f=2;
    				c=1;
    			}
    		}
    	}
    	if(c==1)
    	{
    		cout << "Case " << qq << ": " << "No Ball" << endl;
    	}
    	else
    	{
    		cout << "Case " << qq << ": " << "Thik Ball" << endl;
    	}
    }
    return 0;
}