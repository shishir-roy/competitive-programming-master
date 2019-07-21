/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod;
struct matrix
{
    int row=0,col=0;
    ll mat[17][17];
};
matrix matmult(const matrix &a, const matrix &b)
{
    /// depending on the problem statement mod sum
    assert(a.col==b.row);
    matrix ans;
    ans.row=a.row, ans.col=b.col;
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
    matrix ans;
    ans.row=ans.col=base.row;
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1;qq<=tc;qq++)
    {
    	int a1,b1,c1;
    	cin >> a1 >> b1 >> c1 ;

    	int a2,b2,c2;
    	cin >> a2 >> b2 >> c2;

    	int f0,f1,f2;
    	cin >> f0 >> f1 >> f2;

    	int g0,g1,g2;
    	cin >> g0 >> g1 >> g2;

    	cin >>  mod;

    	cout << "Case " << qq << ":" << endl;

    	int q;
    	cin >> q;

		matrix M,A,B;

		M.row=6,M.col=6;
		M.mat[0][0]=a1 , M.mat[0][1]=b1 , M.mat[0][2]=M.mat[0][3]=M.mat[0][4]=0 , M.mat[0][5]=c1;
		M.mat[1][0]=1, M.mat[1][1]=M.mat[1][2]=M.mat[1][3]=M.mat[1][4]=M.mat[1][5]=0;
		M.mat[2][1]=1, M.mat[2][0]=M.mat[2][2]=M.mat[2][3]=M.mat[2][4]=M.mat[2][5]=0;

		M.mat[3][0]=M.mat[3][1]=0 , M.mat[3][2]=c2, M.mat[3][3]=a2, M.mat[3][4]=b2, M.mat[3][5]=0;
		M.mat[4][3]=1, M.mat[4][1]=M.mat[4][2]=M.mat[4][0]=M.mat[4][4]=M.mat[4][5]=0;
		M.mat[5][4]=1, M.mat[5][0]=M.mat[5][2]=M.mat[5][3]=M.mat[5][1]=M.mat[5][5]=0;

        /*for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                cout << M.mat[i][j] << " ";
            }
            cout << endl;
        }*/
		A.row=6,A.col=1;
		A.mat[0][0]=f2, A.mat[1][0]=f1, A.mat[2][0]=f0, A.mat[3][0]=g2, A.mat[4][0]=g1, A.mat[5][0]=g0;

        /*for(int i=0;i<6;i++)
        {
            cout << A.mat[i][0] << endl;
        }*/
    	while(q--)
    	{
    		int n;
    		cin >> n;

            if(n==0)
            {
                cout << f0%mod << " " << g0%mod << endl;
                continue;
            }
            else if(n==1)
            {
                cout << f1%mod << " " << g1%mod << endl;
                continue;
            }
            else if(n==2)
            {
                cout << f2%mod << " " << g2%mod << endl;
                continue;
            }

    		matrix t=matexpo(M,n-2);
    		B=matmult(t,A);

    		cout << B.mat[0][0]%mod << " " << B.mat[3][0]%mod << endl;
    	}
    }
    return 0;
}
