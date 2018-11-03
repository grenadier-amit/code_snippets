#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vi dist;

void bellman(int v,int s)
{
	dist.clear();
	dist.resize(v,INF);
	dist[s]=0;
	for(int i=0;i<v-1;i++)
	{
		for(int u=0;u<v;u++)
		{
			for(int j=0;j<(int)adjlist[u].size();i++)
			{
				ii v=adjlist[u][j];
				dist[v.first]=min(dist[v.fist],dist[u]+v.second);
			}
		}
	}
}

int main()
{

	return 0;
}
