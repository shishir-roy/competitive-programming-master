/*input
abacaba
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string str;
int palin[5007][5007],dp[5007][5007];
int ispalin(int i,int j)
{
    if(palin[i][j]!=-1) return palin[i][j];
    if(i==j || i>j) return 1;
    if(str[i]==str[j]) return palin[i][j]=ispalin(i+1,j-1);
    else return palin[i][j]=0;
}
int rec(int i,int j)
{
    if(i==j)
        return dp[i][j]=1;
    int& ret=dp[i][j];
    if(ret!=-1)
    {
        return ret;
    }
    if(ispalin(i,j))
    {
        return ret=1+rec(i,(i+j-1)/2);
    }
    else return ret=0;
}
int ara[5007];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    memset(palin,-1,sizeof palin);
    memset(dp,-1,sizeof dp);
    for(int i=0;i<str.size();i++)
    {
        for(int j=i;j<str.size();j++)
        {
            ara[rec(i,j)]++;
        }
    }
//    cout << palin[1][2] << endl;
    for(int i=str.size()-1;i>=0;i--)
    {
        ara[i]+=ara[i+1];
    }
    for(int i=1;i<=str.size();i++)
    {
        cout << ara[i] << " ";
    }
    return 0;
}
