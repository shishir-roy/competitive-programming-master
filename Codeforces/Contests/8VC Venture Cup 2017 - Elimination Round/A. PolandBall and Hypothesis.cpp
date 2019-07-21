#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define DB printf("*****\n")
#define ll long long int
#define pii pair<int,int>
#define fs first
#define sc second
#define inf 2147483647.0
#define eps 1e-12
#define maxn 1000007
#define sh 1000017
#define c(n) (primeflag[n>>5]&(1<<(n&31)))
#define s(n) (primeflag[n>>5]|=(1<<(n&31)))
int primeflag[maxn+7];
void sieve()
{
    int l=sqrt(maxn);
    for(int i=2 ;i<=l ;i++ )
    {
        if(primeflag[i]==0)
        {
            for(int j=i*i ;j<=maxn ;j+=i )
            {
                primeflag[j]=1;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    for(int i=1 ;i<=1000 ;i++ )
    {
        int t=n*i+1;
        if(primeflag[t]==1)
        {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
/*

*/
