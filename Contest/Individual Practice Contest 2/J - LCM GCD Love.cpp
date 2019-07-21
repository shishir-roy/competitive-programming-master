#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl
#define mod                   1000000007
#define inf                   INT_MAX
#define pi                    acos(-1.0)
#define ll                    long long int

#define sf                    scanf
#define pf                    printf
#define pcase(x)              printf("Case %d: ",x)
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)

#define maxn 500007
int ara[maxn];

int flag[maxn];
ll lcm[maxn];
void pre()
{
    for(int i=1; i<maxn; i++)
    {
        lcm[i]=1LL;
    }
    for(int i=2; i<maxn; i*=2)
    {
        lcm[i]*=2LL;
    }


    for(ll i=3; i*i<=maxn; i+=2)
    {
        if(flag[i]==0)
        {
            for(ll j=i*i; j<maxn; j+=(i+i))
            {
                flag[j]=1;
            }

            for(ll j=i; j<maxn; j*=i)
            {
                lcm[j]*=i;
                lcm[j]%=mod;
            }
        }
    }

    for(int i=2; i<maxn; i++)
    {
        lcm[i]= (lcm[i] * lcm[i-1]) % mod ;
    }
}

int tree[4*300000+7][5];
void build(int id,int l,int r)
{
    if(l==r)
    {
        tree[id][0] = tree[id][1] = ara[l];
        return ;
    }
    int mid= (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id][0] = min( tree[id*2][0], tree[id*2+1][0] );
    tree[id][1] = max( tree[id*2][1], tree[id*2+1][1] );
}

int lazy[4*300000+7];
void shift(int id,int l,int r)
{
    if(l!=r)
    {
        tree[id*2][0]+=lazy[id];
        tree[id*2][1]+=lazy[id];

        tree[id*2+1][0]+=lazy[id];
        tree[id*2+1][1]+=lazy[id];

        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];

        lazy[id]=0;
    }
}
void updt(int id,int l,int r,int ql,int qr,int val)
{
    if(lazy[id])
    {
        shift(id,l,r);
    }

    if(l>qr || r<ql ) return ;
    if(l>=ql and r<=qr)
    {
        lazy[id]+=val;
        tree[id][0]+=val;
        tree[id][1]+=val;
        return ;
    }

    int mid = (l+r)/2;
    updt(id*2,l,mid,ql,qr,val);
    updt(id*2+1,mid+1,r,ql,qr,val);

    tree[id][0] = min( tree[id*2][0], tree[id*2+1][0] );
    tree[id][1] = max( tree[id*2][1], tree[id*2+1][1] );
}

pair<int,int> query(int id,int l,int r,int ql,int qr)
{
    if(lazy[id])
    {
        shift(id,l,r);
    }

    if(l>qr ||  r<ql ) return make_pair(9999999,-9999999);
    if(l>=ql and r<=qr)
    {
        return make_pair(tree[id][0], tree[id][1] );
    }

    int mid = (l+r)/2;
    pair<int,int> a,b;
    a=query(id*2,l,mid,ql,qr);
    b=query(id*2+1,mid+1,r,ql,qr);
    tree[id][0] = min( tree[id*2][0], tree[id*2+1][0] );
    tree[id][1] = max( tree[id*2][1], tree[id*2+1][1] );
    return make_pair( min(a.fs,b.fs), max(a.sc,b.sc) );
}
int main()
{
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    pre();
    int n,m;
    sf2(n,m);

    for(int i=0; i<n; i++)
        sf1(ara[i]);
    build(1,0,n-1);
    while(m--)
    {
        int t;
        sf1(t);
        if(t==0)
        {
            int i,j,p;
            sf2(i,j);
            sf1(p);
            updt(1,0,n-1,i,j,p);
//            cout << "after updt " << endl;
//            for(int i=1; i<10; i++)
//            {
//                cout << i << " --> " << tree[i][0] << "  " << tree[i][1] << endl;
//            }
        }
        else if(t==1)
        {
            int i,j;
            sf2(i,j);
            pair<int,int> t = query(1,0,n-1,i,j);
//            cout << "after query " << endl;
//            for(int i=1; i<10; i++)
//            {
//                cout << i << " --> " << tree[i][0] << "  " << tree[i][1] << endl;
//            }
//            cout << t.sc << endl;
            if(t.fs==0)
            {
                pf1(0);
            }
            else
            {
                pf1ll(lcm[t.sc]);
            }

        }
        else if(t==2)
        {
            int i,j;
            sf2(i,j);
            pair<int,int> t = query(1,0,n-1,i,j);
            if(t.fs==0)
            {
                pf1(1);
            }
            else
            {
                pf1ll(lcm[t.fs]);
            }
        }
    }
    return 0;
}
/*
5 5
4 2 5 6 2
0 0 4 -2
1 0 0
1 0 1
0 0 1 4



*/
