#include<bits/stdc++.h>
using namespace std;

#define pii                   pair<int,int>
#define fs                    first
#define sc                    second
#define hi                    cout<<"****"<<endl;
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

#define maxn 100007
vector<pii>gr[507];
int lvl[507],st[507];
string str;
vector<string>vt,ct;
void dfs(int u,int t)
{
    for(int i=0; i<gr[u].size(); i++)
    {
        int v = gr[u][i].fs;
        int x = gr[u][i].sc;
        if(x>=t)
        {
            str.push_back(x+'a');
//            cout << u << " --> " << v << endl;
//            lvl[v] = max(lvl[v],lvl[u] + 1);
            dfs(v,x);
            str=str.substr(0,str.size()-1);
        }
    }
    vt.push_back(str);
}
void dfs2(int u,int t)
{
    for(int i=0; i<gr[u].size(); i++)
    {
        int v = gr[u][i].fs;
        int x = gr[u][i].sc;
        if(x>=t)
        {
            str.push_back(x+'a');
//            cout << u << " --> " << v << endl;
//            lvl[v] = max(lvl[v],lvl[u] + 1);
            dfs(v,x);
            str=str.substr(0,str.size()-1);
        }
    }
    ct.push_back(str);
}
int main()
{
    int n,m;
    sf2(n,m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        char ch;
        sf2(u,v);
        sf(" %c",&ch);
        int t = ch-'a';
        gr[u].push_back({v,t});
    }

//    dfs(1,-1);

    for(int i=1; i<=n; i++)
    {
        memset(lvl,0,sizeof lvl);
        lvl[i] = 1;
//        cout << "call dfs " << i << endl;
        dfs(i,-1);
        int mx = 0;
        for(int j=1; j<=n; j++)
        {
            mx = max(mx,lvl[j]);
        }
        st[i] = mx;
    }

    for(int i=1; i<=n; i++)
    {
        cout << st[i] << " ";
    }
    cout << endl;
    int ans[507][507];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(st[i]<=st[j])
            {
                ans[i][j] = 0;
            }
            else
            {
                ans[i][j] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        vt.clear();
        dfs(i,-1);
        sort(vt.rbegin(),vt.rend());
        string temp = vt[0];
        cout << i << " er jonno " << temp << endl;
        for(int j=1; j<=n; j++)
        {
            ct.clear();

            dfs2(j,-1);
            int f =0;
            for(string s : ct)
            {
                cout << s << " ";
            }
            cout << endl;
            for(int ii=0; ii<ct.size(); ii++)
            {
                if(temp<=ct[ii])
                {
                    cout << i << " er jonno " << temp << " " << j << " er jonno " << ct[ii] << endl;
                    f=1;
                    break;
                }
            }
            if(f)
            {
                pf("B");
            }
            else
            {
                pf("A");
            }
        }
        pf("\n");
    }
    return 0;
}
/*



*/
