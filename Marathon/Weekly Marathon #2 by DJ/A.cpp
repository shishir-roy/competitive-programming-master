#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		int ara[n+8];
		for(int i=0;i<n;i++)
		{
			cin >> ara[i];
		}
		sort(ara,ara+n);
		int flag=1;
		for(int i=n-1;i>=0 and flag;i--)
		{
			for(int j=0;j<i and flag;j++)
			{
//                if(j==i) continue;
				for(int k=j+1;k<i and flag;k++)
				{
//                    if(k==i) continue;
					for(int l=k+1;l<i and flag;l++)
					{
//                        if(l==i) continue;
						if(ara[i]==ara[j]+ara[k]+ara[l])
						{
							flag=0;
							cout << ara[i] << '\n';
						}
					}
				}
			}
		}
		if(flag)
		{
			cout << "no solution" << '\n';
		}
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	int n;
//	while(cin>>n)
//	{
//		if(n==0)
//			return 0;
//		int ara[n+8];
//		for(int i=0;i<n;i++)
//		{
//			cin >> ara[i];
//		}
//		sort(ara,ara+n);
//		int flag=1;
//		for(int i=n-1;i>=0 and flag;i--)
//		{
//			for(int j=0;j<=i and flag;j++)
//			{
//				for(int k=j+1;k<=i and flag;k++)
//				{
//					for(int l=k+1;l<=i and flag;l++)
//					{
//						if(ara[i]==ara[j]+ara[k]+ara[l])
//						{
//							flag=0;
//							cout << ara[i] << '\n';
//						}
//					}
//				}
//			}
//		}
//		if(flag)
//		{
//			cout << "no solution" << '\n';
//		}
//	}
//	return 0;
//}

