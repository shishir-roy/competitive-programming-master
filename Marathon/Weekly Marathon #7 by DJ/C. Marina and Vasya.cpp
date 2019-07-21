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
    int n,t;
    cin >> n >> t;
    string s1,s2;
    cin >> s1 >> s2;
    int a[50],b[50];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for(int i=0;i<n;i++)
    {
    	a[s1[i]-'a']++;
    	b[s2[i]-'a']++;
    }
    string w;
    int d=n-t;
    int x=0;
    for(int i=0;i<26;i++)
    {
    	int t=min(a[i],b[i]);
    	if(w.size()+t<=d)
    	{
    		for(int j=0;j<t;j++)
    		{
    			char ch=i+'a';
    			w+=ch;
    		}
    	}
    	else
    	{
    		int tt=d-w.size();
    		for(int j=0;j<tt;j++)
    		{
    			char ch=i+'a';
    			w+=ch;
    		}
    	}
    }
   /* for(int i=0;i<n;i++)
    {
    	if(w.size()<d)
    	{
    		w+=
    	}
    }*/
    for(int i=0;i<n;i++)
    {
    	if(w.size()<d)
    	{
    		char ch=i+'a';

    	}
    }
    char c;
   	for(int i=0;i<n;i++)
   	{
   		if(a[i]==0 and b[i]==0 and w.size()<n)
   		{
   			c=i+'a';
   		}
   	}
   	while(w.size()<n)
   	{
   		w+=c;
   	}
   	cout << w << endl;
    return 0;
}