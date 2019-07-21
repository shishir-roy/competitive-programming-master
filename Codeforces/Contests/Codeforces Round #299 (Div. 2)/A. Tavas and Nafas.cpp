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
void print(int n)
{
    if(n==1)
    {
        cout << "one";
    }
    else if(n==2)
    {
        cout << "two";
    }
    else if(n==3)
    {
        cout << "three";
    }
    else if(n==4)
    {
        cout << "four";
    }
    else if(n==5)
    {
        cout << "five";
    }
    else if(n==6)
    {
        cout << "six";
    }
    else if(n==7)
    {
        cout << "seven";
    }
    else if (n==8)
    {
        cout << "eight";
    }
    else if(n==9)
    {
        cout << "nine";
    }
}
void print1(int n)
{
    if(n==2)
        cout << "twenty";
    else if(n==3)
        cout << "thirty";
    else if(n==4)
        cout << "forty";
    else if(n==5)
        cout << "fifty";
    else if(n==6)
        cout << "sixty";
    else if(n==7)
        cout << "seventy";
    else if(n==8)
        cout << "eighty";
    else if(n==9)
        cout << "ninety";
}
int main()
{
    int n;
    cin >> n;
    if(n==0)
        cout << "zero";
    else if(n>=1 and n<=9)
        print(n);
    else if(n==10)
        cout << "ten";
    else if(n==11)
        cout << "eleven";
    else if(n==12)
        cout << "twelve";
    else if(n==13)
        cout << "thirteen";
    else if(n==14)
        cout << "fourteen";
    else if(n==15)
        cout << "fifteen";
    else if(n==16)
        cout << "sixteen";
    else if(n==17)
        cout << "seventeen";
    else if(n==18)
        cout << "eighteen";
    else if(n==19)
        cout << "nineteen";
    else if(n==20)
        cout << "twenty";
    else if(n==30)
        cout << "thirty";
    else if(n==40)
        cout << "forty";
    else if(n==50)
        cout << "fifty";
    else if(n==60)
        cout << "sixty";
    else if(n==70)
        cout << "seventy";
    else if(n==80)
        cout << "eighty";
    else if(n==90)
        cout << "ninety";
    else
    {
        int a=n%10;
        n/=10;
        print1(n);
        cout << "-";
        print(a);
    }
//    main();
    return 0;
}
/*

*/
