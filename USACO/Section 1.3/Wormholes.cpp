/*
ID:shishir10
TASK:wormhole
LANG:C++11
*/

#include<bits/stdc++.h>
using namespace std;
int x[17],y[17];
int part[17];
int n;
int nex[17];
bool ok()
{
	for(int s=1;s<=n;s++)
	{
		int ps=s;
//		cout << ps << " theke cycle start hoiteche " << endl;
		for(int i=1;i<=n;i++)
		{
			ps=nex[part[ps]];
//			cout << ps << " " ;
		}
//		cout << endl;
		if(ps!=0) return 1;
	}
	return 0;
}
int solve()
{
    int i,j;
    for( i=1; i<=n; i++)
    {
        if(part[i]==0)
        {
            break;
        }
    }
    if(i>n)
    {
        if(ok())
        	return 1;
        return 0;
    }
    int temp=0;
    for( j=i+1; j<=n; j++)
    {
        if(part[j]==0)
        {
            part[i]=j;
            part[j]=i;
            temp+=solve();
            part[i]=part[j]=0;
        }
    }
    return temp;
}

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> n;
    for(int i=1; i<=n; i++)
    {
        fin >> x[i] >> y[i];
    }
    fin.close();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if( x[j]>x[i] and y[i]==y[j])
			{
				if(nex[i]==0 || (x[j]-x[i]) < (x[nex[i]]-x[i]) )
				{
//                    cout << i << " er nex " << j << endl;
					nex[i]=j;
				}
			}
		}
	}
//	cout << solve() << endl;
    fout << solve() << endl;
    fout.close();
    return 0;
}

