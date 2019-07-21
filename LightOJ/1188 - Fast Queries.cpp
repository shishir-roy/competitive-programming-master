#include<bits/stdc++.h>
using namespace std;
vector< unordered_set<int> >tree(3*100000+7);
int ara[100000+7];
void build(int id,int left,int right)
{
	if(left==right)
	{
		tree[id].insert(ara[left]);
		return;
	}
	int mid=(left+right)/2;
	build(id*2,left,mid);
	build(id*2+1,mid+1,right);
	tree[id].insert(tree[id*2].begin(),tree[id*2].end() );
	tree[id].insert(tree[id*2+1].begin(),tree[id*2+1].end() );
}
set<int> temp;
void query(int id,int left,int right,int i,int j)
{
	if(left>j or right<i)  return ;
	if(left>=i and right<=j)
	{
		temp.insert(tree[id].begin(),tree[id].end());
		return ;
	}
	int mid=(left+right)/2;
	query(id*2,left,mid,i,j);
	query(id*2+1,mid+1,right,i,j);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	for(int qq=1;qq<=tc;qq++)
	{
		int n,q;
		cin >> n >> q;
		for(int i=1;i<=n;i++)
		{
			cin >> ara[i];
		}
		tree.clear();
		build(1,1,n);
		cout << "Case " << qq << ":" << '\n';
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			temp.clear();
			query(1,1,n,l,r);
			cout << temp.size() << endl;
		}
	}
	return 0;
}
