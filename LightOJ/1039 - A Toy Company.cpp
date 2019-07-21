#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define ll long long int
#define maxn 100007

string st,des;
string a[57],b[57],c[57];
set<string>pro;
int n;

int bfs()
{
    map<string,int>mp;
    queue<string>q;
    q.push(st);
    mp[st]=0;
    while(!q.empty())
    {
        string u=q.front();
        q.pop();
        string x=u,y=u;
        for(int i=0;i<3;i++)
        {
            if(u[i]!=des[i])
            {
                x[i]++,y[i]--;
                if(x[i]>'z')x[i]='a';
                if(y[i]<'a')x[i]='z';
                break;
            }
        }

        cout << u << " theke " << x << " " << y << endl;
        if(x==des or y==des)
        {
            break;
        }

        if(mp.find(y)==mp.end())
        {
            if(mp[x]==0)
            {
                mp[x]=mp[u]+1;
                q.push(x);
            }
        }

        if(pro.find(y)!=pro.end())
        {
            if(mp.find(y)==mp.end())
            {
                mp[y]=mp[u]+1;
                q.push(y);
            }
        }
    }
    if(mp.find(des)==mp.end())
    {
        return -1;
    }
    else return mp[des];
}
void mak()
{
    pro.clear();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<a[i].size(); j++)
        {
            for(int k=0; k<b[i].size(); k++)
            {
                for(int l=0; l<c[i].size(); l++)
                {
                    string t;
                    t+=a[i][j];
                    t+=b[i][k];
                    t+=c[i][k];
                    cout << t << endl;
                    pro.insert(t);
                }
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for(int qq=1; qq<=tc; qq++)
    {
        cin >> st >> des;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        mak();
        int t=bfs();
        cout << t << endl;
    }

    return 0;
}

