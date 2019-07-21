#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define MAX 1000000 ///joto porjonto sieve korte cai
#define LMT 1007   /// sqrt(MAX)
#define LEN 100000  ///appx number of primes
#define RNG 100032 ///range for segmentflaged sieve

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

unsigned primeflag[MAX/64+7], segmentflag[RNG/64+7], primes[LEN+7];

/* Generates all the necessary prime numbers and marks them in primeflag[]*/
void sieve()
{
    unsigned long long int i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!chkC(primeflag, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(primeflag, j);
    j=0;
    primes[j++]=2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(primeflag, i))
            primes[j++] = i;
}


vector< pair<int,int> > prime_factorize_of_m(ll n)
{
    vector< pair<int,int> >factors;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < LEN && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
        	int cnt=0;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                cnt++;
            }
            factors.push_back({primes[i],cnt});
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
       	factors.push_back({n,1});
    }
    return factors;
}

int go(int n,int p)
{
    if(n==0) return 0;
	int cnt=0;
	while(n%p==0)
	{
		n/=p;
		cnt++;
	}
	return cnt;
}
int main()
{
	sieve();
	ll n,m;
	while(cin >> n >> m)
	{
		map<int,int>mp;
		vector<int>ans;
		vector< pair<int,int> > pm = prime_factorize_of_m(m);
		for(auto it:pm)
		{
			cout << it.first << " " << it.second << endl;
		}
		cout << endl << endl;
		ll now=1,prev=1;
		for(ll r=0;r<n;r++)
		{
			int ok=1;
			for(int i=0;i<pm.size() and ok==1;i++)
			{
				int p=pm[i].first;
				int cnt=pm[i].second;
				int a=go(n-r,p);
				cout << n-r << " er moddeh " << p << " ache " << a << endl;
				int b=go(r,p);
				cout << r << " er moddeh " << p << " ache " << b << endl << endl;
				int t=mp[p]+a-b;
				/*cout << "pri " << p << " " << t << endl;*/
				if(t<cnt)
				{
					ok=0;
				}
				if(t<0)t=0;
				mp[p]=t;
			}
			/*cout << endl;*/
			if(ok)
			{
				ans.push_back(r+1);
			}
		}

		cout << ans.size() << endl;
		if(!ans.empty())
			cout << ans[0];
		for(int i=1;i<ans.size();i++)
		{
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}
