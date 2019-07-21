#include<bits/stdc++.h>
using namespace std;
vector<int>bam,dan;
vector<int>leftall,rightall;
void recl(int ps,int sum)
{
    if(ps>=bam.size())
    {
        leftall.push_back(sum);
        return;
    }
    for(int i=0;i<3;i++)
    {
        recl(ps+1,sum+bam[ps]*i);
    }
}
void recr(int ps,int sum)
{
    if(ps>=dan.size())
    {
        rightall.push_back(sum);
        return;
    }
    for(int i=0;i<3;i++)
    {
        recr(ps+1,sum+dan[ps]*i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        int n,k;
        cin >> n >> k;
        bam.clear();
        leftall.clear();
        for(int i=0;i<n/2;i++)
        {
            int t;
            cin >> t;
            bam.push_back(t);
        }
        recl(0,0);
        dan.clear();
        rightall.clear();
        for(int i=n/2;i<n;i++)
        {
            int t;
            cin >> t;
            dan.push_back(t);
        }
        recr(0,0);
        sort(leftall.begin(),leftall.end());
        int f=0;
        for(int i=0;i<rightall.size();i++)
        {
            if(binary_search(leftall.begin(),leftall.end(),k-rightall[i]))
            {
                f=1;
            }
        }
        if(f)
        {
            cout << "Case " << qq << ": Yes" << '\n';
        }
        else
        {
            cout << "Case " << qq << ": No" << '\n';
        }
    }
    return 0;
}
