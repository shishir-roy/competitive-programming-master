#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long int sum=0;
	while(n--)
	{
		string str;
		cin >> str;
//		cout << str;
		if(str=="Tetrahedron") sum+=4;
		else if(str=="Cube") sum+=6;
		else if(str=="Octahedron")sum+=8;
		else if(str=="Dodecahedron") sum+=12;
		else if(str=="Icosahedron")sum+=20;
//		cout << sum << endl;
	}
	cout << sum << '\n';
	return 0;
}
