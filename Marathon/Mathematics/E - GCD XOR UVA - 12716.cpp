#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=100;i++)
    {
        for(int j=i+1;j<=100;j++)
        {
            if(__gcd(i,j) == (i^j) )
            {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}
