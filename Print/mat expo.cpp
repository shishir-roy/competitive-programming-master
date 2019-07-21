#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod;
struct matrix
{
    int row=0,col=0;
    ll mat[17][17];
    matrix(int a,int b)
    {
        row=a;
        col=b;
        memset(mat,0,sizeof mat);
    }
};
matrix matmult(const matrix &a, const matrix &b)
{
    /// depending on the problem statement mod sum
    assert(a.col==b.row);
    matrix ans(a.row,b.col);
    for(int i=0; i<a.row; i++)
    {
        for(int j=0; j<b.col; j++)
        {
            ll sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+=(a.mat[i][k]*b.mat[k][j]);
                sum%=mod;
            }
            ans.mat[i][j]=sum;
        }
    }
    return ans;
}
matrix matexpo(matrix base,int p)
{
    /// a matrix is only exponenable when its row==col that means it must have to be a square matrix.
    matrix ans(base.row,base.row);
    for(int i=0; i<base.col; i++)
    {
        for(int j=0; j<base.col; j++)
        {
            ans.mat[i][j]=(i==j);
        }
    }
    while(p)
    {
        if(p&1) ans=matmult(ans,base);
        base=matmult(base,base);
        p>>=1;
    }
    return ans;
}
void show(const matrix& temp)
{
    printf("-----------------------------\n");
    for(int i=0;i<temp.row;i++)
    {
        for(int j=0;j<temp.col;j++)
            cout << temp.mat[i][j] << " ";
        cout << endl;
    }
    printf("-----------------------------\n");
}
int main()
{
    long long int n,m;
    while(cin >> n >> m)
    {
        mod=(1LL<<m);
        matrix M,A,B;
        M.row=M.col=2;
        M.mat[0][0]=M.mat[0][1]=M.mat[1][0]=1;
        M.mat[1][1]=0;
        A.mat[0][0]=1;
        A.mat[0][1]=1;
        A.row=2,A.col=1;
        matrix temp=matexpo(M,n);
        B=matmult(temp,A);
        cout << B.mat[1][0]%mod << endl;
    }
    return 0;
}
