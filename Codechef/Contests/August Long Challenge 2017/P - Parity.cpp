/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void compute_lps(string pat,int *lps)
{
    lps[0]=0;
    int len=0,i=1;
    while(i<pat.size())
    {
        if(pat[i]==pat[len])
        {
            lps[i]=len+1;
            len++,i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin >> a >> b;
    string t;
    t+=b;
    t+='#';
    t+=a;
    int lps[1007];
    compute_lps(t,lps);
    int tt=lps[t.size()-1];
    int id=t.size()-1;
    string c,d;
    for(int i=0;i<a.size()-tt;i++)
    {
       c+=a[i];
    }
    for(int i=a.size()-tt;i<a.size();i++)
    {
      d+=a[i];
    }
    /*cout << c << " " << d << endl;*/
   	int od=0;
   	for(auto i:d)
   	{
   		if(i=='1')
   			od++;
   	}
   	int oc=0;
   	for(auto i:c)
   	{
   		if(i=='1')
   			oc++;
   	}
    int ob=0;
    for(auto i:b)
    {
      if(i=='1')
        ob++;
    }
   	int nd=ob-od;
   	if(nd<=oc)
   	{
   		cout << "YES" ;
   	}
   	/*else if(nd==1 and oc%2==1)
   	{
   		cout << "YES";
   	}*/
   	else
   	{
   		cout << "NO";
   	}
    return 0;
}