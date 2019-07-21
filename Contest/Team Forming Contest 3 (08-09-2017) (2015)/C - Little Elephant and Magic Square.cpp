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
    int ara[5][5],sum[5];
    memset(sum,0,sizeof sum);
    int mx=0;
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cin >> ara[i][j];
    		sum[i]+=ara[i][j];
    	}
    	mx=max(mx,sum[i]);
    }
    while(1)
    {
    	mx++;
//    	cout << mx << endl;
    	int t1=mx-sum[0];
    	int t2=mx-sum[1];
    	int t3=mx-sum[2];
    	if(t1+t2+t3==ara[0][2]+t2+ara[2][0])
    	{
    		ara[0][0]=t1;
    		ara[1][1]=t2;
    		ara[2][2]=t3;
    		for(int i=0;i<3;i++)
    		{
    			for(int j=0;j<3;j++)
    			{
    				cout << ara[i][j] << " ";
    			}
    			cout << endl;
    		}
    		return 0;
    	}
//    	if(mx==15)
//            break;
    }
    return 0;
}
