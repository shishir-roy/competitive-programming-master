#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class LongMansionDiv2 {
public:
	long long minimalTime(int, vector <int>);
};

long long LongMansionDiv2::minimalTime(int M, vector <int> t) {
	sort(t.begin(),t.end());
	long long int sum=0;
	for(int i=0;i<t.size();i++)
		sum+=(long long int)t[i];
    cout << sum << endl;
    cout << t[0] << endl;
    cout << M-1 << endl;
    cout << t[0]*M-1 << endl;
	sum+=((long long int)t[0]*(long long int)(M-1) );
	return sum;
}

int main()
{
	int m=4;
	vector<int>vt={3, 2, 4, 2};
    LongMansionDiv2 t;
    long long int f=t.minimalTime(4,vt);
    cout << f << endl;
	return 0;
}
