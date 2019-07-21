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
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	int n,m;
    	cin >> n >> m;
    	int minsalary[n+7];
    	for(int i=0;i<n;i++)
 		{
 			cin >> minsalary[i];
 		}
 		vector< pair<int,int> > vt,temp;
 		for(int i=0;i<m;i++)
 		{
 			int salary,vacant;
 			cin >> salary >> vacant;
 			vt.push_back({salary,vacant});
 		}
 		temp=vt;
 		vector<string>qual;
 		for(int i=0;i<n;i++)
 		{
 			string str;
 			cin >> str;
 			qual.push_back(str);
 		}
 		int cnt=0;
 		ll sum=0;
 		for(int i=0;i<n;i++)
 		{
 			int mx=minsalary[i];
            int id=-1;
 			for(int j=0;j<m;j++)
 			{
 				if(qual[i][j]=='1' && temp[j].second>0 && temp[j].first>=minsalary[i])
 				{
                    if(temp[j].first>=mx)
                    {
                        mx=temp[j].first;
                        id=j;
                    }
 				}
 			}
            if(id!=-1)
            {
                temp[id].second--;
                sum+=mx;
                /*cout << sum << " sum print " << cnt  << endl;*/
                cnt++;
            }
 			
 		}
        int tt=0;
        for(int i=0;i<m;i++)
        {
            if(vt[i].second==temp[i].second)
            {
                tt++;
            }
        }
 		cout << cnt << " " << sum << " " << tt << endl;
    }
    return 0;
}