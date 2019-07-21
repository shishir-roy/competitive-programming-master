#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007
int lps[maxn];
void compute_lps(string pat)
{
    int j=0,i=1;
    lps[0]=0;
    while(i<pat.size())
    {
        if(pat[i]==pat[j])
        {
            lps[i]=j+1;
            i++,j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int main()
{
    compute_lps("abcdabab");
    for(int i=0;i<8;i++)
    {
        cout << lps[i] << " ";
    }
    return 0;
}
