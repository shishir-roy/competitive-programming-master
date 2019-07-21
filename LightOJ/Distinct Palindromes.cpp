#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
#include <map>
#include <algorithm>
#define MAXL 1111
#define MODD 1000000007
#define ll long long
using namespace std;


int npos[27][MAXL+1];
int ppos[27][MAXL+1];

int dp[1111][1111];

int Count(int st,int en)
{

    if (dp[st][en]!=-1)
        return dp[st][en];

    int ans=1;
    for(int c=0; c<26; c++)
    {
        int p1 = npos[c][st];
        int p2 = ppos[c][en];


        if (p1 == -1 || p2 == -1)
            continue;
        if (p1 > p2)
            continue;
        if (p1 == p2)
        {
            ans++;
            continue;
        }

        ans += 1+Count(p1+1,p2-1);
        if (ans >= MODD)
            ans-=MODD;


    }

    return dp[st][en]=ans;

}

int main()
{


    string S;
    cin>>S;

    int L=S.size();
    for(int c=0; c<26; c++)
    {
        npos[c][L]=-1;
    }

    for(int j=L-1; j>=0; j--)
    {
        for(int c=0; c<26; c++)
        {
            if (S[j]==c+'a')
                npos[c][j]=j;
            else
                npos[c][j]=npos[c][j+1];
        }
    }
    for(int c=0; c<26; c++)
    {
        ppos[c][0]=-1;
    }

    ppos[S[0]-'a'][0]=0;

    for(int j=1; j<L; j++)
    {
        for(int c=0; c<26; c++)
        {
            if (S[j]==c+'a')
                ppos[c][j]=j;
            else
                ppos[c][j]=ppos[c][j-1];
        }
    }


    for(int i=0; i<1111; i++)
        for(int j=0; j<1111; j++)
            dp[i][j]=-1;

    cout << (Count(0,L-1)+MODD-1)%MODD <<endl;
}
