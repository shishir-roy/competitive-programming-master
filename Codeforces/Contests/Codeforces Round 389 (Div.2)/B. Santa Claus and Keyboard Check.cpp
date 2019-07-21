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
int main()
{
    string pat,text;
    cin >> pat >> text;
    map<char,char>mp;
    map<char,char>::iterator it,it1;
    map<char,char>mpp;
    for(int i=0 ;i<pat.size() ;i++ )
    {
        it=mp.find(pat[i]);
        it1=mpp.find(text[i]);
        if(it==mp.end())
        {
            mp[pat[i]]=text[i];
        }
        else
        {
            if(it->second!=text[i])
            {
                cout << "-1" << '\n';
                return 0;
            }
        }
        if(it1==mpp.end())
        {
            mpp[text[i]]=pat[i];
        }
        else
        {
            if(it1->second!=pat[i])
            {
                cout << "-1" << '\n';
                return 0;
            }
        }
    }
    vector<char>vt;
    for(it=mp.begin() ;it!=mp.end() ;it++ )
    {
        if(it->fs!=it->sc)
        {
            if(find(vt.begin(),vt.end(),it->fs)!=vt.end() and find(vt.begin(),vt.end(),it->sc)!=vt.end()) continue;
            vt.push_back(it->fs);
            vt.push_back(it->sc);
        }
    }
    for(int i=0 ;i<vt.size() ;i++ )
    {
        int cnt=0;
        for(int j=0 ;j<vt.size() ;j++ )
        {
            if(vt[i]==vt[j])
                cnt++;
        }
        if(cnt>1)
        {
            cout << "-1" << '\n';
            return 0;
        }
    }
    cout << vt.size()/2 << endl;
    for(int i=0 ;i<vt.size() ;i+=2 )
    {
        cout << vt[i] << ' ' << vt[i+1] << '\n';
    }
    return 0;
}
/*

*/
