#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
#include <climits>
#define ll long long
#define MOD 1000000007
#define mx 3005
#define mkp make_pair
#define MAXN 3000005
using namespace std;

int tree[MAXN][2], ptr = 0, cnt[MAXN];
int fun(int n, int i)
{
    return bool(n & (1<<i));
}

long long ans = 0;
const int deb = 0;
void insert(int n)
{
    int tmp = 0;
    for(int i = 23 - deb; i>=0; i--)
    {
        int d = fun(n, i);
        cnt[tmp]++;
        if(tree[tmp][d] == -1) tree[tmp][d] = ++ptr;
        tmp = tree[tmp][d];
    }
    cnt[tmp]++;
}
void search(int n, int k)
{
    int tmp = 0;
    for(int i = 23 - deb; i>=0; i--)
    {
        int d = fun(n, i), dk = fun(k, i);
        if(tree[tmp][d^dk^1] != -1 && dk == 1)
        {
            ans += cnt[tree[tmp][d^dk^1]];
        }
        if(tree[tmp][d^dk] != -1)
        {
            tmp = tree[tmp][d^dk];
        }
        else break;
    }
}
void clear()
{
    for(int i = 0; i<=ptr; i++)
    {
        tree[i][0] = tree[i][1] = -1;
        cnt[i] = 0;
    }
    ptr = 0;
    ans = 0;
}
int main()
{
    memset(tree, -1, sizeof tree);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int ara[n];
        clear();
        insert(0);
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &ara[i]);
            if(i) ara[i] ^= ara[i-1];
            search(ara[i], k);
            insert(ara[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
