/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    char ch;
    int f=0;
    string ss,tt;
    ss+='\`';
    ss+='\`';
    tt+='\'';
    tt+='\'';
//    cout << ss << " " << tt << endl;
    while(scanf("%c",&ch)==1)
    {
    	if(ch==34)
    	{
    		if(f==0)
    		{
    			cout << ss;
    			f=1;
    		}
    		else if(f==1)
    		{
    			cout << tt;
    			f=0;
    		}
    	}
    	else cout << ch ;
//        printf("%d",ch);
    }
    return 0;
}
