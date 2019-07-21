#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long t,n,sqrt_n;
    long long mod = 1000000007;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=25;i++)
        {
            cout << i << " " << 25/i << endl;
        }
        cin>>n;
        sqrt_n = sqrt(n);
        long long sum = 0;
        //finding summation of N/i *i from i=1 to sqrt(N)
        for(long long i=1; i<=sqrt_n; i++)
            sum = sum + (n/i)*i;
        // after i=sqrt(N), there is no need to iterate further bcoz value of N/i will either decrease by 1 or remain same
        for(long long i=n/sqrt_n-1; i>=1; i--)
        {
            long long lower_limit = n/(i+1);
            long long upper_limit = n/i;
            long long tmp = ((upper_limit*(upper_limit+1))/2 - (lower_limit*(lower_limit+1))/2);
            sum = sum + tmp*i;
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}
