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
char str[7][7];
int fx[]= {-1,1,0,0,1,1,-1,-1};
int fy[]= {0,0,-1,1,1,-1,1,-1};
bool valid(int x,int y)
{
    if(x>=0 && x<4 && y>=0 && y<4)
        return 1;
    return 0;
}
int main()
{
    for(int i=0 ; i<4 ; i++ )
    {
        sf("%s",str[i]);
    }
    string cmp[]= {"xx.", "x.x",".xx"};
    for(int i=0 ; i<4 ; i++ )
    {
        for(int j=0 ; j<4 ; j++ )
        {
            if(str[i][j]=='x')
            {
                for(int k=0 ;k<8 ;k++ )
                {
                    if(valid(i+fx[k]*2,j+fy[k]*2))
                    {
                        int x=i,y=j;
                        string s;
                        for(int qq=0 ;qq<3 ;qq++ )
                        {
                            s+=str[x][y];
                            x+=fx[k];
                            y+=fy[k];
                        }
                        if(s==cmp[0] || s==cmp[1] || s==cmp[2])
                        {
                            cout << "YES";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
/*
.oxx
x...
.o..
o...
*/
