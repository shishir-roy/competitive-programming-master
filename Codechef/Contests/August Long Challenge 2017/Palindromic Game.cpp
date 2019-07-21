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
    	string s,t;
    	cin >> s >> t;
    	sort(s.begin(),s.end());
    	sort(t.begin(),t.end());
  		int ara[34];
  		memset(ara,0,sizeof ara);
  		int f=0,tt=0;
  		for(int i=0;i<s.size();i++)
  		{
  			ara[s[i]-'a']++;
  		}
  		int temp[34];
  		memset(temp,0,sizeof temp);
  		for(int i=0;i<s.size();i++)
  		{
  			temp[t[i]-'a']++;
  		}
  		for(int i=0;i<min(s.size(),t.size());i++)
  		{
  			if(ara[i]>=2 and temp[i]==0)
  			{
  				f=1;
  			}
  		}
  		int in=0;
  		if(s.size()-1==t.size())
  		{
  			for(int i=0,j=0;i<s.size() and j<t.size();i++)
  			{
  				if(s[i]!=t[j] and in==0)
  				{
  					in=1;
  				}
  				else if(s[i]!=t[j] and in==1)
  				{
  					in=2;
  				}
  				else
  				{
  					j++;
  				}
  			}
  		}
  		/*cout << "in " << in << endl;*/
  		if(f==1 or in==1)
  		{
  			cout << "A" << endl;
  		}
  		else
  		{
  			cout << "B" << endl;
  		}
    }
    return 0;
}