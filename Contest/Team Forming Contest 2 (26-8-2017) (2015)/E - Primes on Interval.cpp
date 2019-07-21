/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000050
ll base[MAX/64],primes[MAX];

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

/* Generates all the necessary prime numbers and marks them in base[]*/
int no=0;
void sieve()
{
    unsigned i, j, k;
    int LMT=sqrt(MAX);
    for(i=3; i<LMT; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    j=0;
    primes[j++]=2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
    no=j-1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    /*cout << no << " " << primes[no]  << endl;*/
    ll a,b,k;
    cin >> a >> b >> k;
    /*int id=upper_bound(primes,primes+no,a)-primes;
    if(primes[id-1]==a)
    {
    	id=id-1;
    	int t=id+k;
    	if(t>b)
    	{
    		cout << -1;
    	}
    	else
    	{
    		cout << primes[t]-a;
    	}
    }
    else
    {
    	int t=id+k;
    	if(t>b)
    	{
    		cout << -1;
    	}
    	else
    	{
    		cout << primes[t]-a;
    	}
    }*/
    int cnt=0;
    int i=0;
    for(i=0;i<no;i++)
    {
    	if(primes[i]>=a and primes[i]<=b)
    	{
    		cnt++;
    	}
    	if(primes[i]>b)
    		break;
    	if(cnt==k+1)
    	{
    		if(primes[i]-a-1 > b-a+1)
    		{
    			cout << -1 ;
    			return 0;
    		}
    		cout << primes[i]-a-1 << endl;
    		return 0;
    	}
    }
        		if(primes[i]-a > b-a+1)
    		{
    			cout << -1 ;
    			return 0;
    		}
    if(cnt==k)
    {
    	cout << primes[i]-a << endl;
    	return 0;
    }
    cout << -1;
    return 0;
}