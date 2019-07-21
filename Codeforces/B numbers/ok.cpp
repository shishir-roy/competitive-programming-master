/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ara[10][10];
int n;
vector<int>vt;
void rec(int i,int j,int num)
{
	if(i>=3 || j>=6) return;
	for(int t=0;t<6;t++)
	{
		vt.push_back(ara[i][j]);
		rec(i,t,ara[i][j]);
	}
	for(int t=0;t<6;t++)
	{
		vt.push_back(i+1,t,num*10+ara[i][j]);
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<6;j++)
    	{
    		cin >> ara[i][j];
    	}
    	sort(ara[i],ara[i]+6);
    }
    rec(0,0,0);
    sort(vt.begin(),vt.end());
    for(int i=0;i<vt.size();i++)
    {
    	cout << vt[i] << endl;
    }
    return 0;
}