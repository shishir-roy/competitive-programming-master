#include<bits/stdc++.h>
using namespace std;
long long int cnt=0;
void merge(int ara[],int p,int q,int r)
{
	queue<int>left,right;
	for(int i=p;i<=q;i++)
		left.push(ara[i]);
	for(int i=q+1;i<=r;i++)
		right.push(ara[i]);
	int k=p;
	//cout << "while loop er age " << endl;
	while(k<=r)
	{
		if(right.empty())
		{
			ara[k]=left.front();
			left.pop();
		}
		else if(left.empty())
		{
			ara[k]=right.front();
			right.pop();
		}
		else
		{
			if(left.front()>right.front())
			{
				ara[k]=right.front();
				cnt+=left.size();
				right.pop();
			}
			else
			{
				ara[k]=left.front();
				left.pop();
			}
		}
		k++;
	}
	//cout << "merging sesh hoilo " << endl;
}
void merge_sort(int ara[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
	//	cout << "calling " << endl;
		merge_sort(ara,p,q);
		merge_sort(ara,q+1,r);
	//	cout << "merging suru " << endl;
		merge(ara,p,q,r);
	}
}
		
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)return 0;
		int ara[n+7];
		for(int i=0;i<n;i++)
			cin >> ara[i];
		cnt=0;
		merge_sort(ara,0,n-1);
		cout << cnt << '\n';
	}
	return 0;
}
