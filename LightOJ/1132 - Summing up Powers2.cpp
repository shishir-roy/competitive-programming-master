
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100007

ll mod=4294967296;
unsigned int bio[105][105];
void binomial()
{
    for(int i=0;i<75;i++)
    {
        bio[i][0]=bio[i][i]=1;
        bio[i][1]=i;

        for(int j=2;j<i;j++)
        {
            bio[i][j]=( bio[i-1][j]+bio[i-1][j-1] )%mod;
        }
    }
}


struct matrix
{
    int row=57,col=57;
    unsigned int mat[107][107];

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
            unsigned int sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+=(a.mat[i][k]*b.mat[k][j]);
            }
            ans.mat[i][j]=sum%mod;
        }
    }
    return ans;
}

matrix matexpo(matrix base,ll p)
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
//    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    binomial();
//    cout << bio[25][0] << endl;
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
        ll n,k;
        cin >> n >> k;
        if(n==1)
        {
            cout << "Case " << qq << ": " << 1 << endl ;
            continue;
        }

        matrix M(k+2,k+2);
        M.mat[0][0]=1;
        for(int i=1;i<k+2;i++)
        {
            M.mat[0][i]=bio[k][k-(i-1)] ;
            M.mat[1][i]=bio[k][k-(i-1)];
        }
        for(int i=2;i<k+2;i++)
        {
            int t=k-(i-1);
            for(int j=i;j<k+2;j++)
            {
                M.mat[i][j]=bio[k-(i-1)][t--];
            }
        }
        matrix A(k+2,1);
        for(int i=0;i<k+2;i++)
        {
            A.mat[i][0]=1;
        }

        M=matexpo(M,n-1);
        A=matmult(M,A);
        cout << "Case " << qq << ": " << A.mat[0][0] << endl ;
    }
    return 0;
}
