/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>vt;
int n,m,f=0;
int dp[1007][1007][2];
int rec(int ps,int sum,int cnt)
{
	/*cout << "sum " << sum << endl;*/
	if(sum%m==0 and cnt>0)
	{
		f=1;
		return 1;
	}
	if(f) return 1;
	if(ps>=n)
	{
		return 0;
	}
	int &ret=dp[ps][sum][cnt];
	if(ret!=-1) return ret;
	ret=rec(ps+1,(sum+vt[ps])%m,cnt|1) | rec(ps+1,sum,cnt);
	return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	vt.push_back(t);
    }
    if(n>=m)
    {
    	cout << "YES";
    	return 0;
    }
    memset(dp,-1,sizeof dp);
    rec(0,0,0);
    if(f)
    {
    	cout << "YES" ;
    }
    else
    {
    	cout << "NO";
    }
    return 0;
}