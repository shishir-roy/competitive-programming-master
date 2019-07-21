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
int l;
char str[25],res[25];
int ara[25];
bool check(int ps,int val)
{
    memset(ara,0,sizeof ara);
    cout << ps << ' ' << val << endl;
    for(int i=0 ; i<=ps ; i++ )
    {
        ara[res[i]]++;
        if(ara[res[i]]>2) return false;
    }
    for(int i=0 ;i<=ps ;i++ )
    {
        cout << ara[i] ;
    }
    cout << endl;
    if(ara[val]>=2) return false;
    return 1;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll num;
    while(sf("%lld",&num)==1)
    {
        memset(ara,0,sizeof ara);
        int flag=0,it;
        l=sprintf(str,"%lld",num);
        for(int i=0 ; i<l ; i++ )
        {
            ara[str[i]-'0']++;
            if(ara[str[i]-'0']>2)
            {
                flag=1;
                it=i;
                break;
            }
            res[i]=str[i]-'0';
        }
        if(!flag) cout << num << endl;
        else
        {
            for(int i=it ; i>=0 ; i-- )
            {
                int a=str[i]-'0';
                for(int j=a-1 ; j>=0 ; j-- )
                {
                    if(check(i,j))
                    {
                        res[i]=j;
                        it=i;
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }
            cout << it+1 << endl;
            for(int j=it+1; j<l ; j++ )
            {
                for(int i=9 ; i>=0 ; i-- )
                {
                    if(check(j,i))
                    {
                        res[j]=i;
                        break;
                    }
                    else
                    {
                        for(int i=0 ;i<l ;i++ )
                        {
                            pf("%d",res[i]) ;
                        }
                        cout << endl;

                    }
                }
            }
            cout << " result " << endl;
            for(int i=0 ;i<l ;i++ )
            {
                pf("%d",res[i]);
            }
            cout << endl;
        }
    }
    return 0;
}
/*
2210102960
*/
