#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	vector<string>vt;
	while(getline(cin,str))
	{
		vt.push_back(str);
	}
	sort(vt.begin(),vt.end());
	//cout << "input sesh " << endl;
	for(int i=0;i<vt.size();i++)
	{
		string temp=vt[i];
		for(int i=0;i<temp.size();i++)
		{
			string a=temp.substr(0,i);
			string b=temp.substr(i,temp.size()-1);
//			cout << a << " " << b << endl;
			if(binary_search(vt.begin(),vt.end(),a) && binary_search(vt.begin(),vt.end(),b) )
			{
				cout << temp << '\n';
				break;
			}
		}
	}
	return 0;
}
