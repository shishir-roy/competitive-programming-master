#include<bits/stdc++.h>
using namespace std;
vector<long long int>lucky,vlucky;
void lucky_gen(long long int num)
{
    if(num>1000000100000LL)
    {
        return;
    }
    if(num!=0)
    {
        lucky.push_back(num);
    }
    lucky_gen(num*10+4);
    lucky_gen(num*10+7);
}
set<long long int>st;
void vlucky_gen(int ps,long long int num)
{
    if(num>1000000100000LL)
    {
        return;
    }
    if(num<=1000000100000LL and num>1)
    {
        st.insert(num);
    }
    if(ps>=lucky.size())
    {
        return;
    }
    if(num<=1000000100000LL/lucky[ps])vlucky_gen(ps+1,num);
    if(num<=1000000100000LL/lucky[ps])vlucky_gen(ps+1,num*lucky[ps]);
    if(num<=1000000100000LL/lucky[ps])vlucky_gen(ps,num*lucky[ps]);
}
int main()
{
//    clock_t b=clock();
    lucky_gen(0);
    sort(lucky.begin(),lucky.end());

    vlucky_gen(0,1LL);
    copy(st.begin(),st.end(),back_inserter(vlucky));
    sort(vlucky.begin(),vlucky.end());
//    clock_t e=clock();
//    cout << (float)(e-b)/CLOCKS_PER_SEC << endl;
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        long long int a,b;
        cin >> a >> b;
        long long int ans=upper_bound(vlucky.begin(),vlucky.end(),b)-lower_bound(vlucky.begin(),vlucky.end(),a-1);
        cout << "Case " << qq << ": " << ans << '\n';
    }
    return 0;
}
