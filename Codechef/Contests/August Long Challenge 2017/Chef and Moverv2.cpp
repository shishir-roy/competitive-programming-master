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
    	int n,d;
    	cin >> n >> d;
    	int ara[n+7];
    	ll sum=0;
    	for(int i=0;i<n;i++)
    	{
    		cin >> ara[i];
    		sum+=ara[i];
    	}
    	if(sum%n!=0)
    	{
    		cout << -1 << endl;
    	}
    	else
    	{
    		ll avg=sum/n,ans=0,f=1;
    		for(int i=0;i<d;i++)
    		{
    		    /*cout << "inf " << endl;*/
    			ll s=0,a=0,prev=0,cnt=0;
    			for(int j=i;j<n;j+=d)
    			{
    			   /* cout << ara[j] << " ";*/
    				s+=ara[j];
    				ll t=ara[j]+prev;
    				prev=0;
    				if(t>avg)
    				{
    					ll com=t-avg;
    					ans+=com;
    					prev=com;
    				}
    				else if(t<avg)
    				{
    					ll com=avg-t;
    					ans+=com;
    					prev=-com;
    				}/*
    				cout << ara[j] << " " << prev << endl;
    				cout << "ans " << ans << endl;*/
    				cnt++;
    			}
    		/*	cout << endl;
    			cout << "s " << s << endl;*/
    			if(s%cnt!=0)
    			{
    				f=0;
    				break;
    			}
    			a=s/cnt;
    			if(a!=avg)
    			{
    				f=0;
    				break;
    			}
    		}
    		if(f)
    		{
    			/*cout << "final " << ans << endl;*/
    			cout << ans << endl;
    		}
    		else
    		{
    			cout << -1 << endl;
    		}
    	}
    }
    return 0;
}
