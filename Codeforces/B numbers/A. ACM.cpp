#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[10];
    int sum=0;
    for(int i=0;i<6;i++)
    {
        cin >> ara[i];
        sum+=ara[i];
    }
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            for(int k=j+1;k<6;k++)
            {
                if(ara[i]+ara[j]+ara[k]==sum/2 and sum%2==0)
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
