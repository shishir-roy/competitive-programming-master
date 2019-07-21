/*
ID:shishir10
LANG:C++11
TASK:milk3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a,b,c;
vector<int>vt;
int vis[30][30][30];
void rec(int ta,int tb,int tc)
{
	/*cout <<ta << " " << tb << " " << tc << endl;*/
	if(vis[ta][tb][tc]==0)
	{
		vis[ta][tb][tc]=1;
		// a->b
		if(ta>b-tb) rec(ta-b+tb,b,tc); else rec(0,tb+ta,tc);
		// b->a
		if(tb>a-ta) rec(a,tb-a+ta,tc); else rec(ta+tb,0,tc);
		// a->c
		if(ta>c-tc) rec(ta-c+tc,tb,c); else rec(0,tb,tc+ta);
		//c->a
		if(tc>a-ta) rec(a,tb,tc-a+ta); else rec(ta+tc,tb,0);
		//b->c
		if(tb>c-tc) rec(ta,tb-c+tc,c); else rec(ta,0,tc+tb);
		//c->b
		if(tc>b-tb) rec(ta,b,tc-b+tb); else rec(ta,tb+tc,0);
	}
}
int main()
{
	freopen("milk3.in","r",stdin);
 	freopen("milk3.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 	cin >> a >> b >> c;
 	rec(0,0,c);
 	for(int i=0;i<=b;i++)
 	{
 		for(int j=0;j<=c;j++)
 		{
 			if(vis[0][i][j])
 			{
 				vt.push_back(j);
 			}
 		}
 	}
 	sort(vt.begin(),vt.end());
 	if(!vt.empty())
 		cout << vt[0];
 	for(int i=1;i<vt.size();i++)
 	{
 		cout << " " << vt[i] ;
 	}
 	cout << endl;
    return 0;
}