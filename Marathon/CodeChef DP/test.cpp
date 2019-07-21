#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int SQ;
struct data{
    int l, r, idx;
    bool operator < (const data &a) const{
        if(l/SQ == a.l/SQ) return r < a.r;
        else return l/SQ < a.l/SQ;
    }
}Q[mx];
int ara[mx];
int cnt[1000005];
long long ans[mx];
long long counti = 0;

inline void add(int i)
{
    counti += 1ll * ara[i] * (2 * cnt[ara[i]] + 1);
    cnt[ara[i]]++;
}
inline void remove(int i)
{
    counti += 1ll * ara[i] * (- 2 * cnt[ara[i]] + 1);
    cnt[ara[i]]--;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++)
        scanf("%d", &ara[i]);
    for(int i = 0; i<m; i++){
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].idx = i;
    }
    SQ = sqrt(n);
    sort(Q, Q+m);
    cnt[0] = 2;
    //Here prevL and prevR represents inclusive information
    int prevL = 0, prevR = 0;
    for(int i = 0; i<m; i++)
    {
        while(prevL < Q[i].l)
            remove(prevL++);
        while(prevL > Q[i].l)
            add(--prevL);
        while(prevR < Q[i].r)
            add(++prevR);
        while(prevR > Q[i].r)
            remove(prevR--);
        ans[Q[i].idx] = counti;
    }
    for(int i = 0; i<m; i++)
        printf("%lld\n", ans[i]);

    return 0;
}