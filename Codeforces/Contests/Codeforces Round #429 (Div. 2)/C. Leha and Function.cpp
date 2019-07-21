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
    int ara[n+7];
    vector< pair<int,int> >vt;
    vector<int>fir,sc;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	fir.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin >> t;
    	vt.push_back({t,i});
    }
    sort(fir.rbegin(),fir.rend());
    sort(vt.begin(),vt.end());
    for(int i=0;i<n;i++)
    {
    	ara[vt[i].second]=fir[i];
    }
    for(int i=0;i<n;i++)
    	cout << ara[i] << " ";
    return 0;
}