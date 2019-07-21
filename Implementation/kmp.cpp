#include<bits/stdc++.h>
using namespace std;
void compute_lps(string pat,int lps[])
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
void KMP(string txt,string pat)
{
    int lps[pat.size()+7];
    compute_lps(pat,lps);
    int i=0,j=0;
    while(i<txt.size())
    {
        if(txt[i]==pat[j])
        {
            i++,j++;
        }
        if(j==pat.size())
        {
            cout << "found " << i-j << endl;
            j=lps[j-1];
        }
        else if(i<txt.size() and txt[i]!=pat[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    KMP("abcabcabcabc","abc");
    return 0;
}
