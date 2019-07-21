#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >>k ;
    vector<int>vt,numbers;
    for(int i=0; i<k; i++)
    {
        int t;
        cin >> t;
        vt.push_back(t);
    }
    for(int i=1; i<=n; i++)
    {
        numbers.push_back(i);
    }
    vector<int>ans;
    int j=0;
    for(int i=0; i<k; i++)
    {
        int t=1;
        while(t<=vt[i])
        {
            t++;
            j++;
            if(j>=numbers.size())
                j=0;
        }
        ans.push_back(numbers[j]);
        numbers.erase(numbers.begin()+j);
        if(j>=numbers.size())
            j=0;
    }
    for(auto it: ans)
        cout << it << " ";
    return 0;
}
