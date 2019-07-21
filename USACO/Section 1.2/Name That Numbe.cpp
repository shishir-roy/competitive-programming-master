/*
ID:shishir10
LANG:C++
TASK:namenum
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
vector<char>vt;
vector<string>col;
vector<string>dd;
string gn;
int n;
int flag=1;
ofstream fout("namenum.out") ;
ifstream fin("namenum.in") ,fdict("dict.txt");
void name(int ps)
{
    if(ps>=n)
    {
        string str;
        for(int i=0;i<vt.size();i++)
        {
            str+=vt[i];
        }
        if(binary_search(col.begin(),col.end(),str))
        {
            flag=0;
           fout << str << '\n';
        }
        return;
    }
    for(int i=0;i<3;i++)
    {
        vt.push_back(dd[gn[ps]-'0'-2][i]);
        name(ps+1);
        vt.pop_back();
    }
}
int main()
{
    dd.push_back("ABC");
    dd.push_back("DEF");
    dd.push_back("GHI");
    dd.push_back("JKL");
    dd.push_back("MNO");
    dd.push_back("PRS");
    dd.push_back("TUV");
    dd.push_back("WXY");
    string t;
    while(fdict>>t)
    {
        //cout << t << endl;
        col.push_back(t);
    }
    fin>>gn;
    n=gn.size();
    name(0);
    if(flag) fout << "NONE" << '\n';
    return 0;
}
