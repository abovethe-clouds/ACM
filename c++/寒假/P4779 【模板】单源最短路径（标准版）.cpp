#include <bits/stdc++.h>
using namespace std;

int n, m, s;

vector<pair<int,int>> v[100005];

bool vis[100005];
int dis[100005];

// priority_queue<pair<int,int>> q;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

void dijkstra()
{
	for (int i = 1; i <= n; i++)
    {
        dis[i]=1000000005;
    }
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x])
            continue;
        vis[x]=true;
        for (auto p : v[x])
        {
            int y=p.first;
            int l=p.second;
            if(dis[y]>dis[x]+l)
            {
                dis[y]=dis[x]+l;
                q.push(make_pair(dis[y],y));
            }
        }
    }
	
}

int main()
{
	cin >> n >> m >> s;
	for(int i=1;i<=m;i++)
    {
        int s,z,q;
        cin>>s>>z>>q;
        v[s].push_back(make_pair(z,q));
    }
	dijkstra();
	
	for(int i = 1; i <= n; i++){
		cout << dis[i] <<' ';
	}
	
	return 0;
}