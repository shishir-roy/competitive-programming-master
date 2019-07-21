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
#define maxn 100000
vector<int>gr[maxn],node;
int n;
//int vist[maxn],cnt=0,n;
//void dfs(int u,int p)
//{
//    vist[u] = 1;
//    cnt++;
//    if(cnt <= n)
//    {
//        node.push_back(u);
//    }
//    for(int v : gr[u])
//    {
//        if(v!=p)
//        {
//            dfs(v,u);
//            if(cnt < n)
//            {
//                node.push_back(u);
//            }
//        }
//    }
//}

void DFS(int s)
{
    // Initially mark all verices as not visited
    vector<bool> visited(maxn+7);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
//            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then puah it
        // to the stack.
        for (auto i = gr[s].begin(); i != gr[s].end(); ++i)
            if (!visited[*i])
            {
                if(!node.empty() and node.back()!=s)
                    node.push_back(s);
                node.push_back(*i);
                stack.push(*i);
            }
    }
}
int main()
{
    sf1(n);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int mn=maxn+7,id=-1;
    for(int i=1; i<=n; i++)
    {
        if(gr[i].size()<mn)
        {
            mn=gr[i].size();
            id=i;
        }
    }
//    dfs(id,-1);
    node.push_back(id);
    DFS(id);
    pf1(node.size()-1);
    for(int x : node)
    {
        pf("%d ",x);
    }
    return 0;
}
/*



*/
