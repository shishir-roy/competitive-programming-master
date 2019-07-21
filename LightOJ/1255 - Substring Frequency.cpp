#include<bits/stdc++.h>
using namespace std;
void compute_lps(string pat,int *lps)
{
    int len=0,i=1;
    lps[0]=0;
    while(i<pat.size())
    {
        if(pat[i]==pat[len])
        {
            lps[i]=len+1;
            len++,i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int KMP(string txt,string pat)
{
    int lps[pat.size()+7];
    compute_lps(pat,lps);
    int i=0,j=0,ans=0;
    while(i<txt.size())
    {
        if(txt[i]==pat[j])
        {
            i++,j++;
        }
        if(j==pat.size())
        {
            ans++;
            j=lps[j-1];
        }
        else if(txt[i]!=pat[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else i++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        string txt,pat;
        cin >> txt >> pat;
        int t=KMP(txt,pat);
        cout << "Case " << qq << ": " << t << '\n';
    }
    return 0;
}
