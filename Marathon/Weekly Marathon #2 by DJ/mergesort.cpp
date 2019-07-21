#include<bits/stdc++.h>
using namespace std;
void merge(int ara[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-p;
	int left[n1+3],right[n2+3];
	for(int i=0;i<n1;i++)
		left[i]=ara[i+p];
	for(int i=0;i<n2;i++)
		right[i]=ara[i+q+1];
	left[n1]=321;
	right[n2]=321;
	int i=0,j=0,k=p;
	cout << "copy sesh " << endl;
	while(k<=r)
	{
		if(left[i]<=right[j])
		{
			ara[k]=left[i];
			i++;
		}
		else
		{
			ara[k]=right[j];
			j++;
		}
		k++;
	}
}
void mergesort(int ara[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(ara,p,q);
		mergesort(ara,q+1,r);
		merge(ara,p,q,r);
	}
}
int main()
{
	int ara[]={1,78,5,7,99,4,6,8};
	mergesort(ara,0,7);
	for(int i=0;i<8;i++)
		cout << ara[i] << " ";
	return 0;
}
