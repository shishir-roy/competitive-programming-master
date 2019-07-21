#include<bits/stdc++.h>
using namespace std;
int ara[1000007],cnt[1000007];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    int ansx=0,ansy=0,x=0,y=0,len=0,temp=0;
    memset(cnt,0,sizeof cnt);
    for(; y<n; y++)
    {
        if(cnt[ara[y]]==0) temp++;
        cnt[ara[y]]++;

        while(temp>k)
        {
            if(cnt[ara[x]]==1)
            {
                temp--;
                cnt[ara[x]]=0;
            }
            else
            {
                cnt[ara[x]]--;
            }
            x++;
        }
        if(y-x+1>len && temp<=k)
        {
            len=y-x+1;
            ansx=x,ansy=y;
        }
    }

    printf("%d %d",ansx+1,ansy+1);
    return 0;
}
