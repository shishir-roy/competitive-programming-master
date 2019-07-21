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
int target1[15+7],target2[15+7],given[20],hint[20];
int n,m,gcnt;
void make()
{
    int f,j=0;
    for(int i=0 ; i<m ; i++ )
    {
        int t=hint[i];
        if(i==0)
        {
            f=1;
        }
        for(int k=0; k<t ; k++ )
        {
            if(f)
            {
                target1[j++]=0;
            }

            else
            {
                target1[j++]=1;
            }
        }
        if(f)f=0;
        else f=1;
    }
    ///
    j=0;
    for(int i=0 ; i<m ; i++ )
    {
        int t=hint[i];
        if(i==0)
        {
            f=0;
        }
        for(int k=0; k<t ; k++ )
        {
            if(f)
            {
                target2[j++]=0;
            }

            else
            {
                target2[j++]=1;
            }
        }
        if(f)f=0;
        else f=1;
    }
}
int cal1()
{
    int cnt=0;
    for(int i=0 ; i<n ; i++ )
    {
        if(target1[i]) cnt++;
    }
    if(cnt!=gcnt) return inf;
    int x=0,y=0;
    cnt=0;
    for( ; x<n && y <n ; )
    {
        if(target1[x]==given[y] )
        {
            cnt+=(x-y);
            swap(target1[x],target1[y]);
            if(x==y)
            {
                x++,y++;
            }
            else
                y++;
        }
        else
        {
            x++;
        }
    }
    return cnt;
}
int cal2()
{
    int cnt=0;
    for(int i=0 ; i<n ; i++ )
    {
        if(target2[i]) cnt++;
    }
    if(cnt!=gcnt) return inf;
    int x=0,y=0;
    cnt=0;
    for( ; x<n && y <n ; )
    {
        if(target2[x]==given[y])
        {
            cnt+=(x-y);
            swap(target2[x],target2[y]);
            if(x==y)
            {
                x++,y++;
            }
            else
                y++;
        }
        else
        {
            x++;
        }
    }
    return cnt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(sf("%d%d",&n,&m)==2)
    {
        gcnt=0;
        for(int i=0 ; i<n ; i++ )
        {
            sf("%d",&given[i]);
            if(given[i]==1) gcnt++;
        }
        for(int i=0 ; i<m ; i++ )
        {
            sf("%d",&hint[i]);
        }
        make();
        cout << "target1 " << endl;
        for(int i=0 ; i<n ; i++ )
        {
            cout << target1[i];
        }
        cout << endl;
        cout << "target2 " << endl;
        for(int i=0 ; i<n ; i++ )
        {
            cout << target2[i];
        }
        cout << endl;
        int a=cal1();
        int b=cal2();
        cout << "after target1 " << endl;
        for(int i=0 ; i<n ; i++ )
        {
            cout << target2[i];
        }
        cout << endl;
        cout << "a " << a << " b " << b << endl;
        int ans=min(a,b);
        cout << a << '\n';
    }
    return 0;
}
/*

*/
