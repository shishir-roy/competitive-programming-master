///*input
//
//*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long int
//int a,b,k;
//#define MAX 1000007
//#define LMT sqrt(MAX)
//
//unsigned base[MAX/64],nprimes[MAX];
//
//#define chkS(x,n) (x[n>>6]&(1<<((n>>1)&31)))
//#define setS(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
//
//void sieve()
//{
//    unsigned i, j, k;
//    for(i=3; i<LMT; i+=2)
//        if(!chkS(base, i))
//            for(j=i*i, k=i<<1; j<MAX; j+=k)
//                setS(base, j);
//    nprimes[1]=0,nprimes[2]=1;
//    ll sum=1;
//    for(j=3;j<MAX;j++)
//    {
//    	if(j%2==0)
//    	{
//    		nprimes[j]=nprimes[j-1];
//    	}
//    	else if(!chkS(base,j))
//    	{
//    		nprimes[j]=nprimes[j-1]+1;
//    	}
//    	else
//    	{
//    		nprimes[j]=nprimes[j-1];
//    	}
//    }
//}
//inline bool ok(int l)
//{
//	for(int x=a;x<=b-l+1;x++)
//	{
//		int y=x+l-1;
//		if(nprimes[y]-nprimes[x-1]<k)
//			return 0;
//	}
//	return 1;
//}
//int bs(int l,int r)
//{
//	int ans=-1;
//	while(l<=r)
//	{
//		int mid=(l+r)/2;
//        /*cout << mid << " " << ok(mid) << endl;*/
//		if(ok(mid))
//		{
//			ans=mid;
//			r=mid-1;
//		}
//		else
//		{
//			l=mid+1;
//		}
//	}
//	return ans;
//}
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    sieve();
//    cin >> a >> b >> k;
//    /*cout << nprimes[10] << " " << nprimes[6] << endl;
//    cout << ok(4) << endl;*/
//    int ans=bs(1,b-a+1);
//    cout << ans << endl;
//    return 0;
//}
int lca(int u, int v)
{
	if(depth[v]<depth[u])
		swap(u,v);
	int diff=depth[v]-depth[u];
	for(int i=0;i<level;i++)
		if((diff>>i)&1)
			v=par[v][i];
	if(v==u)
		return v;
	for(int i=level;i>=0;i--)
		if(par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
	return par[u][0];
}
