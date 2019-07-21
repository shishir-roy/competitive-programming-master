/*input

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int fx[]={-1,1,0,0,1,1,-1,-1};
int fy[]={0,0,-1,1,1,-1,1,-1};
int flag[10][10];
pair<int,int> path[10][10];
std::vector< pair<int,int> > vt;
string nota[]={"U","D","L","R","RD","LD","RU","LU"};
vector<string>temp;
void bfs(int sx,int sy)
{
	memset(path,-1,sizeof path);
	memset(flag,-1,sizeof flag);
	queue< pair<int,int> >Q;
	Q.push({sx,sy});
	flag[sx][sy]=0;
	while(!Q.empty())
	{
		pair<int,int> u=Q.front();
		Q.pop();
		for(int i=0;i<8;i++)
		{
			int vx=u.first+fx[i];
			int vy=u.second+fy[i];
			if(vx<8 and vx>=0 and vy<8 and vy>=0 and flag[vx][vy]==-1)
			{
				/*cout << u.first <<" " << u.second << " theke jacci " << vx <<" " << vy << endl;*/
				flag[vx][vy]=flag[u.first][u.second]+1;
				path[vx][vy]={u.first,u.second};
				/*cout << u.first << " " << u.second << endl;*/
				Q.push({vx,vy});
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    /*cout << s[1] << endl;*/
    int sy=s[0]-'a';
    int sx='8'-s[1];
    int ty=t[0]-'a';
    int tx='8'-t[1];
    /*cout <<sx << " " << sy << endl;
    cout << tx << " " << ty << endl;
    cout <<"###" << endl;*/
    bfs(sx,sy);
    /*cout << "bfs sesh " << endl;
    cout << path[sx][sy].first << " " << path[sx][sy].second << endl;*/
    while(path[tx][ty].first!=-1 and path[tx][ty].second!=-1)
    {
    	/*cout << tx << " " << ty << endl;
    	cout << path[tx][ty].first << " " << path[tx][ty].second << endl;*/
    	int ax=path[tx][ty].first,bx=path[tx][ty].second;
    	/*cout << ax << " " << bx << endl;*/
    	vt.push_back({tx,ty});
    	tx=ax;
    	ty=bx;
    	/*vt.push_back({tx,ty});*/
    	/*cout << tx << " " << ty << endl  << endl;*/
    }
    /*cout << " loop " << endl;*/
  	vt.push_back({sx,sy});
    reverse(vt.begin(),vt.end());
   /* cout << "path shuru " << endl;
    for(auto it : vt)
    {
    	cout << it.first << " " << it.second << endl;
    }
    cout << "path sesh" << endl;*/
    cout << vt.size()-1 << endl;
    for(int i=0;i<vt.size()-1;i++)
    {
    	for(int j=0;j<8;j++)
    	{
    		/*cout << vt[i].first << " " << vt[i].second << endl;
    		cout << vt[i].first+fx[i] << " " << vt[i].second+fy[i] << endl << endl;*/
    		if(vt[i].first+fx[j]==vt[i+1].first and vt[i].second+fy[j]==vt[i+1].second)
    		{
    			/*cout <<"if er vitre " << endl;*/ 
    			temp.push_back(nota[j]);
    		}
    	}
    }
    for(auto it:temp)
    {
    	cout << it <<endl;
    }
    return 0;
}