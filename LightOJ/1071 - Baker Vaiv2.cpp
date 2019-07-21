#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007
#define D(x) cout << #x " = " << (x) << endl
int ara[107][107],r,c;
int dp[107][107][107];

int rec(int row,int c1,int c2)
{
//    cout << row << " " << c1 << " " << c2 << endl;
    if(c1>=c2 || c2 > c || c1>c || row>r)
        return 0;
    if(row==r and c1==c-1 and c2==c) return ara[row][c1]+ara[row][c2];
//    if(row==r and c1==c-1 )
//        return ara[row][c-1];
//    if(row==r and c2==c)
//        return ara[row][c2];

    int& ret=dp[row][c1][c2];
    if(ret!=-1) return ret;
    ret=INT_MIN;

    if(row==r)
    {
//        ret=max(ret, rec(row,c1+1,c2)+ara[row][c1] );
//        ret=max(ret, rec(row,c1,c2+1)+ara[row][c2] );
        if(c1<c2 and c2<c)
        {
            ret=max(ret, rec(row,c1,c2+1)+ara[row][c2] );
        }
        if(c1<c2-1 and c1<c-1)
        {
            ret=max(ret, rec(row,c1+1,c2)+ara[row][c1] );
        }
        return ret;
    }

    if(c1<c2 and c2<c)
    {
        ret=max(ret, rec(row,c1,c2+1)+ara[row][c2] );
    }
    if(c1<c2-1 and c1<c-1)
    {
        ret=max(ret, rec(row,c1+1,c2)+ara[row][c1] );
    }
    if(row<=r)
    {
        ret=max(ret, rec(row+1,c1,c2)+ara[row][c1]+ara[row][c2] );
    }

//    ret=max(ret, rec(row+1,c1,c2)+ara[row][c1]+ara[row][c2] );
//    ret=max(ret, rec(row,c1,c2+1)+ara[row][c2] );
//    ret=max(ret, rec(row,c1+1,c2)+ara[row][c1] );
//    cout << "row " << row << " *** " << c1 << " " << c2  << " er jonno " << ret << endl;
    return ret;
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cin >> r >> c;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                cin >> ara[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
//        cout << "******" << endl << endl;
        int ans=rec(1,1,2);
        cout << "Case " << qq << ": " << ans << endl;
    }
    return 0;
}

