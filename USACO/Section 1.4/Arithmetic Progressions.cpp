/*
ID:shishir10
LANG:C++11
TASK:ariprog
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	freopen("ariprog.in","r",stdin);
 	freopen("ariprog.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    bool vis[m*m+m*m+7];
    memset(vis,0,sizeof vis);
    vector<int>vt;
    int mx=INT_MIN;
    for(int i=0;i<=m;i++)
    {
    	for(int j=0;j<=m;j++)
    	{
    		int t=i*i+j*j;
    		if(!vis[t])
            {
                vis[t]=1;
                vt.push_back(t);
                mx=max(mx,t);
            }
    	}
    }
    sort(vt.begin(),vt.end());
    vector< pair<int,int> >ans;
    for(int i=0;i<vt.size();i++)
    {
        for(int j=i+1;j<vt.size();j++)
        {
            int f=1;
            if(vt[i]+(vt[j]-vt[i])*(n-1)>mx) break;
            for(int cnt=0;cnt<n;cnt++)
            {
                ll t=vt[i]+(vt[j]-vt[i])*cnt;
                if(!vis[t])
                {
                    f=0;
                }
                if(t>mx) break;
            }
            if(f)
            {
                ans.push_back({vt[j]-vt[i],vt[i]});
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.empty())
    {
    	cout << "NONE" << endl;
    }
    else
    {
	    for(int i=0;i<ans.size();i++)
	    {
	    	cout << ans[i].second << " " << ans[i].first << endl;
	    }
    }
	return 0;
}
