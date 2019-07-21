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
    vector<ll>a,b;
    vector< pair<int,int> > all;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	a.push_back(t);
    	all.push_back({t,-1});
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
    	int t;
    	cin >> t;
    	b.push_back(t);
    	all.push_back({t,-2});
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(all.begin(),all.end());
    ll mx=INT_MIN,ansa=0,ansb=0;
    for(int i=0;i<all.size();i++)
    {
    	if(all[i].second==-1)
    	{
    		int d=all[i].first-1;
    		int t=upper_bound(a.begin(),a.end(),d)-a.begin();
    		/*cout << t << endl;*/
    		int ta=t*2+(n-t)*3;
    		t=upper_bound(b.begin(),b.end(),d)-b.begin();
    		int tb=t*2+(m-t)*3;
    		int dif=ta-tb;
    		/*cout << d << " d er jonno " << ta << " " << tb << " " <<  mx  << endl;*/
    		if(dif>mx)
    		{
    			/*cout << "###" << endl;*/
    			mx=dif;
    			/*cout << "d " << d << endl;*/
    			ansa=ta,ansb=tb;
    		}
    		else if(dif==mx)
    		{
    			if(ta>ansa)
    			{
    				ansa=ta;
    				ansb=tb;
    			}
    		}
    	}
    	else
    	{
    		int d=all[i].first+1;
    		int t=upper_bound(a.begin(),a.end(),d)-a.begin();
    		int ta=t*2+(n-t)*3;
    		t=upper_bound(b.begin(),b.end(),d)-b.begin();
    		int tb=t*2+(m-t)*3;
    		int dif=ta-tb;
    		if(dif>mx)
    		{
    			mx=dif;
    			/*cout << "d " << d << endl;*/
    			ansa=ta,ansb=tb;
    		}
    		else if(dif==mx)
    		{
    			if(ta>ansa)
    			{
    				ansa=ta;
    				ansb=tb;
    			}
    		}
    	}
	    int d=all[i].first;
		int t=upper_bound(a.begin(),a.end(),d)-a.begin();
		int ta=t*2+(n-t)*3;
		t=upper_bound(b.begin(),b.end(),d)-b.begin();
		int tb=t*2+(m-t)*3;
		int dif=ta-tb;
		/*cout << d << " d er jonno " << ta << " " << tb << " " <<  mx  << endl;*/
		if(dif>mx)
		{
			mx=dif;
			/*cout << "d " << d << endl;*/
			ansa=ta,ansb=tb;
		}
		else if(dif==mx)
		{
			if(ta>ansa)
			{
				ansa=ta;
				ansb=tb;
			}
		}
    }
    cout << ansa << ":" << ansb << endl;
    return 0;
}