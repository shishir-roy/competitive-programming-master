#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        int n;
        cin >> n;
        int ara[n+7];
        for(int i=0; i<n; i++)
        {
            cin >> ara[i];
        }
        int f=1,t=1;
        vector<int>vt;
        int a[10];
        memset(a,0,sizeof a);
        for(int i=0,j=n-1; i<=n/2; i++,j--)
        {
            if(ara[i]<0 || ara[i]>7)
            {
                f=0;
                break;
            }
            if(ara[i]!=ara[j])
            {
                f=0;
                break;
            }
            if(ara[i+1]-ara[i]>1)
            {
                f=0;
                break;
            }
            a[ara[i]]++;
        }
        for(int i=1; i<=7; i++)
        {
            if(a[i]==0)
            {
                f=0;
                break;
            }
            /*else
            	{
            		cout << a[i] << " ";
            	}*/
        }
        /*cout << endl;*/
        /*  for(auto i :vt)
          {
          	cout << i << ' ';
          }
          cout << endl;*/
        /*for(int i=1;i<vt.size();i++)
        {
        	if(vt[i]-vt[i-1]!=1)
        	{
        		f=0;
        		break;
        	}
        }*/
        if(f)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
    return 0;
}

