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
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	mp[t]++;
    }
    vector< pair<int,int> >p;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
    	p.push_back({it->second,it->first});
    }
    sort(p.begin(),p.end());
    vector< pair<int,pair<int,int> > > ans;
 	for(int i=0;i<p.size()-2;i++)
 	{
 		if(p[i].first==0)
 			continue;
 		int t=min(p[i].first,min(p[i+1].first,p[i+2].first));
 		int s=t;
 		while(s--)
 		{
 			ans.push_back({p[i].second,{p[i+1].second,p[i+2].second}});
 		}
 		p[i].first-=t;
 		p[i+1].first-=t;
 		p[i+2].first-=t;
 	}
 	cout << ans.size() << endl;
 	for(int i=0;i<ans.size();i++)
 	{
 		vector<int>temp;
 		temp.push_back(ans[i].first);
 		temp.push_back(ans[i].second.first);
 		temp.push_back(ans[i].second.second);
 		sort(temp.rbegin(),temp.rend());
 		for(auto i:temp)
 			cout << i << " ";
 		cout << endl;
 	}
    return 0;
}