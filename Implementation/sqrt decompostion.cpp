/*input

*/
// d-query problem ac solution
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 200000+7
int block;
struct  data
{
	int l,r,idx;
	bool operator < (const data &a) const
	{
		if(l/block!=a.l/block) return l/block < a.l/block;
		return r < a.r;
	}
}Q[maxn];

// the size of the cnt should be equal to largest element of the array
int ara[maxn],cnt[1000000+7],ans[maxn],counti=0;

inline void add(int ps)
{
	cnt[ara[ps]]++;
	if(cnt[ara[ps]]==1)
		counti++;
}
inline void remove(int ps)
{
	cnt[ara[ps]]--;
	if(cnt[ara[ps]]==0)
		counti--;
}
int main()
{
    int n;
    cin >> n;
    block=sqrt(n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d", &ara[i]);
    	/*cin >> ara[i];*/
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
    	scanf("%d %d",&Q[i].l, &Q[i].r);
    	/*cin >> Q[i].l >> Q[i].r;*/
    	Q[i].idx=i;
    }
    int curL=0,curR=0;
    sort(Q,Q+m);
    add(0);
    for(int i=0;i<m;i++)
    {
    	while(curL < Q[i].l)
    		remove(curL++);
    	while(curL > Q[i].l)
    		add(--curL);
    	while(curR < Q[i].r)
    		add(++curR);
    	while(curR > Q[i].r)
    		remove(curR--);
    	ans[Q[i].idx]=counti;
    }
    for(int i=0;i<m;i++)
    	printf("%d\n",ans[i]);
    return 0;
}