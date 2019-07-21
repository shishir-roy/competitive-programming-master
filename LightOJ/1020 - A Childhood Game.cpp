#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int qq=1;qq<=tc;qq++)
    {
        long long int n;
        char str[10];
        scanf("%lld",&n);
        scanf("% s",str);
        cin >> str;
        printf("Case %d: ",qq);
        if(str[0]=='A')
        {
            if(n%3==1)
            {
                cout << "Bob";
            }
            else
            {
                cout << "Alice";
            }
        }
        else
        {
            if(n%3==0)
            {
                cout << "Alice";
            }
            else
            {
                cout << "Bob";
            }
        }
        printf("\n");
    }
    return 0;
}
