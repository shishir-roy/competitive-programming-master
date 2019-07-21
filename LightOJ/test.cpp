#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rep(i,n) for(i=0;i<(n);i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define MAXN 105

int n, m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][3];

int go(int row, int c1, int c2, int nextMove)
{
    if(row == n-1 && c2 == m-1 && c1 == m-2 && nextMove == 0) return 0;
    if(dp[row][c1][c2][nextMove] != -1) return dp[row][c1][c2][nextMove];

    int &res = dp[row][c1][c2][nextMove];
    res = 0;
    if(nextMove == 0)   //move the left one to the right
    {
        if(c1+1 < c2) res = max(res, go(row, c1+1, c2, 0) + a[row][c1+1]);
        res = max(res, go(row, c1, c2, 1)); //finished moving
    }
    else if(nextMove == 1)   //move the right one to the right
    {
        if(c2+1 < m) res = max(res, go(row, c1, c2+1, 1) + a[row][c2+1]);
        if(c2 > c1) res = max(res, go(row, c1, c2, 2)); //finished moving
    }
    else   //move both to the immediate bottom row
    {
        if(c1 < c2 && row+1 < n) res = max(res, go(row+1, c1, c2, 0) + a[row+1][c1] + a[row+1][c2]);
    }
    return res;
}

int main()
{
    int T, kase=1, i, j;
    int res;
    scanf(" %d",&T);
    while(T--)
    {
        scanf(" %d %d",&n,&m);
        rep(i,n) rep(j,m) scanf(" %d",&a[i][j]);
        printf("Case %d: ",kase++);
        memset(dp, -1, sizeof(dp));
        res = go(0, 0, 0) + a[0][0];
        printf("%d\n",res);
    }
    return 0;
}
