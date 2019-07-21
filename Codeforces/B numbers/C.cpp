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
vector<int>vt;
void seive()
{
    int flag[1000007];
    memset(flag,0,sizeof flag);
    for(int i=3; i<=1000; i+=2)
    {
        if(flag[i]==0)
        {
            for(int j=i*i; j<=1000006; j+=(2*i))
            {
                flag[j]=1;
            }
        }
    }
    vt.push_back(2);
    for(int i=3; i<1000007; i+=2)
    {
        if(flag[i]==0)
        {
            vt.push_back(i);
        }
    }
}
vector< ll > temp;
void func(int n)
{
//    DB;
    for(int i=0; i<vt.size() and vt[i]<=n; i++)
    {
        int t=vt[i];
//        cout << t << endl;
        int cnt=0;
        int m=t;
        while(t<n)
        {
            cnt++;
            t*=m;
//            cout << t << endl;
        }
        if(t==n)
            temp.push_back(t);
        else temp.push_back(t/m);
    }
}
ll lcm(ll a,ll b,ll c)
{
    ll aa=__gcd(a,b);
    ll bb=__gcd(aa,c);
    return (a*b*c)/bb;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    seive();
//    cout << vt.back();
    ll n;
    cin >> n;
//    const clock_t begin_time = clock();
    ll ans=n;
    ans=max(ans,max(n*(n-1),n*(n-1)*(n-2)) );
    func(n);
//    ll ans=1;
    sort(temp.begin(),temp.end(),greater<int>());
//    for(int i=0;i<temp.size();i++) cout << temp[i] << " ";
    if(temp.size()>=1) ans=max(ans,temp[0]);
    if(temp.size()>=2) ans=max(ans,temp[0]*temp[1]);
    if(temp.size()>=3) ans=max(ans,temp[0]*temp[1]*temp[2]);
    vector<int>vtt;
    int m=n;
//    cout << ans << endl;
    while(1)
    {
        vtt.push_back(m--);
        if(m==0 || vtt.size()>500)
        {
            break;
        }
    }
//    for(int i:vtt) cout << i << " ";
    sort(vtt.begin(),vtt.end(),greater<int>());
//    cout << lcm(50,50,50) << endl;
    for(int i=0; i<vtt.size(); i++)
    {
        for(int j=i+1; j<vtt.size(); j++)
        {
            for(int k=j+1; k<vtt.size(); k++)
            {
                if(lcm(vtt[i],vtt[j],vtt[k])>ans)
                {
//                    cout << vtt[i] << " " << vtt[j] << " " << vtt[k] << endl;
                    ans=lcm(vtt[i],vtt[j],vtt[k]);
//                    cout << i << " " << j << " " << k << endl;
                }

            }
        }
    }
    cout << ans;
//    cout << endl << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    return 0;
}
/*

*/
