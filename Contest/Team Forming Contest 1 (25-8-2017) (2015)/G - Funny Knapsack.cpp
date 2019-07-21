/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>vt,fir,sec;
ll sum=0;
int p,q;
void rec1(int ps)
{
	if(ps>=p)
	{
		fir.push_back(sum);
		return;
	}
	sum+=vt[ps];
	rec1(ps+1);
	sum-=vt[ps];
	rec1(ps+1);
}
void rec2(int ps)
{
	if(ps>=q)
	{
		sec.push_back(sum);
		return;
	}
	sum+=vt[ps];
	rec2(ps+1);
	sum-=vt[ps];
	rec2(ps+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	ll n,k;
    	cin >> n >> k;
    	vt.clear();
    	fir.clear();
    	sec.clear();
    	for(int i=0;i<n;i++)
    	{
    		ll t;
    		cin >> t;
    		vt.push_back(t);
    	}
    	p=n/2;
    	q=n;
    	sum=0;
    	rec1(0);
    	/*for(int i: fir)
    		cout << i << " ";
    	cout << endl;*/
    	sum=0;
    	rec2(p);
    	/*for(int i: sec)
    		cout << i  << " ";
    	cout << endl;*/
    	sort(sec.begin(),sec.end());
    	ll ans=0;
    	/*cout << lower_bound(sec.begin(),sec.end(),3)-sec.begin() << endl;*/
    	for(int i=0;i<fir.size();i++)
    	{
    		/*int t=upper_bound(sec.begin(),sec.end(),k-fir[i])-sec.begin();*/
    		/*cout << "t " << t << endl;*/
    		ans+=(upper_bound(sec.begin(),sec.end(),k-fir[i])-sec.begin());
    	}
    	cout << "Case " << qq << ": " << ans << endl;
    }
    return 0;
}