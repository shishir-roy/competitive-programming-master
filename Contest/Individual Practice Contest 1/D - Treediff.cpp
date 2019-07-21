#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
vector<int>gr[maxn];
set<int>st[maxn];
int val[maxn];
int ans[maxn];
void dfs(int u)
{
    ans[u]=INT_MAX;
    for(int v : gr[u])
    {
        dfs(v);
        ans[u]=min(ans[u], ans[v]);
        if( st[u].size() > st[v].size() )
        {
            swap(st[v],st[u]);
        }
        for(auto x : st[v])
        {
            auto it = st[u].upper_bound(x);
            if(it != st[u].end() ) ans[u]=min(ans[u], (int)abs(x - *it ) );
            if(it != st[u].begin() )
            {
                --it;
                ans[u]=min(ans[u], abs( x - *it) );
            }
            st[u].insert(x);
        }
    }
    if(st[u].empty()) st[u].insert(val[u]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=2; i<=n; i++)
    {
        int x;
        cin >> x;
        gr[x].push_back(i);
    }
    for(int i=n-m+1; i<=n; i++)
        cin >> val[i];
    dfs(1);
    cout << ans[1];
    for(int i=2; i<=(n-m); i++)
    {
        cout << " " << ans[i];
    }
    return 0;
}
