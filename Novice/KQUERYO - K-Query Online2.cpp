#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
vector<int>vt[4*maxn];
int ara[maxn];
int k;
/*
void  merge(vector<int>& left,vector<int>&right,vector<int>& s)
{
	//vector<int>s;
	int i=0,j=0;
	int l=left.size(),r=right.size();
	int k=0;
	while(k<l+r)
	{
		if(right.empty())
		{
			s.push_back(left.front());
			left.erase(left.begin());
		}
		else if(left.empty())
		{
			s.push_back(right.front());
			right.erase(right.begin());
		}
		else if(right.front()<left.front())
		{
			s.push_back(right.front());
			right.erase(right.begin());
		}
		else 
		{
			s.push_back(left.front());
			left.erase(left.begin());
		}
		//cout << "***** " << s[k] << endl;
		k++;
	}
	//return s;
}
*/
void build(int id,int l,int r)
{
	if(l==r)
	{
		vt[id].push_back(ara[l]);	
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	//merge(vt[id*2],vt[id*2+1],vt[id]);
	vt[id].resize(vt[id*2].size()+vt[id*2+1].size());
	merge(vt[id*2].begin(),vt[id*2].end(),vt[id*2+1].begin(),vt[id*2+1].end(),vt[id].begin());
}
int query(int id,int l,int r,int i,int j)
{
	if(l>j or r<i)
		return 0;
	if(l>=i and r<=j)
	{
	//	cout  << id << " " << vt[id].size() << " " << vt[id].size()-(upper_bound(vt[id].begin(),vt[id].end(),k)-vt[id].begin()) << endl;
		return vt[id].size()-(upper_bound(vt[id].begin(),vt[id].end(),k)-vt[id].begin());
	}
	int mid=(l+r)/2;
	return query(id*2,l,mid,i,j)+query(id*2+1,mid+1,r,i,j);
}	
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    const clock_t begin_time = clock();
	int n;
	sf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sf("%d",ara+i);
	}
	int q;
	build(1,1,n);
	//cout << vt[2].size() << endl;
	sf("%d",&q);
	//cout << "query suru " << endl;
	int last=0;
	while(q--)
	{
		int a,b,c;
		sf("%d%d%d",&a,&b,&c);
		int i=a^last;
		int j=b^last;
		k=c^last;
		//cout << i << " " << j << " " << k << endl;
		last=query(1,1,n,i,j);
		pf("%d\n",last);
	} 
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/

