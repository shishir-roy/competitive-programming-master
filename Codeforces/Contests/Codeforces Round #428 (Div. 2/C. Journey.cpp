/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>gr[100000+7];
double sum=0.0,cnt=0.0;
int dist[100000+7];
long double pro[100000+7];
void dfs(int u,int par)
{
	for(auto v: gr[u])
	{
		if(v!=par)
		{
			if(par!=-1)
			{
				pro[v]=pro[u]/(gr[u].size()-1);
			}
			else
			{
				pro[v]=pro[u]/gr[u].size();
			}
			dist[v]=dist[u]+1;
			/*cout << u << " ---> " << v << endl;
			cout << "pro " << pro[u] << " " << pro[v] << endl;
			cout << "dist " << dist[u] << " " <<dist[v] << endl;*/
			dfs(v,u);
		}
	}
}
/*void bfs(int src)
{
	queue<int>Q;
	Q.push(src);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(auto v:gr[u])
		{
			if(dist[v]==0)
			{
				dist[v]=dist[u]+1;
				pro[v]=1/gr.
				Q.push(v);
			}
		}
	}
}*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
    	int u,v;
    	cin >> u >> v;
    	gr[u].push_back(v);
    	gr[v].push_back(u);
    }
    pro[1]=1.0;
    dfs(1,-1);
    for(int i=1;i<=n;i++)
    {
    	if(gr[i].size()==1)
    	{
    		sum+=(dist[i]*pro[i]);
    		/*cnt++;*/
    	}
    }
   /* for(int i=1;i<=n;i++)
    {
    	cout << dist[i] <<" " << pro[i] << endl;
    }*/
    cout << fixed << setprecision(10) << sum << endl;
    return 0;
}