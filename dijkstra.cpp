#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <vii> adjlist;
vi dist;

void dijkstra(int s)
{
	dist[s]=0;
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	pq.push(make_pair(0,s));

	while(!pq.empty())
	{
		ii front=pq.top();
		pq.pop();
		int d=front.first,u=front.second;
		if(d>dist[u])
			continue;
		for(int j=0;j<(int)adjlist[u].size();j++)
		{
			ii v=adjlist[u][j];
			if(dist[u]+v.second < dist[v.first])
			{
				dist[v.first]=dist[u]+v.second;
				pq.push(make_pair(dist[v.first],v.first));
			}
		}
	}
}

int main()
{
	int n,e,s;
	printf("enter no of vertices and no of edges respectively\n");
	scanf("%d %d",&n,&e);

	adjlist.clear();
	adjlist.resize(n);
	
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);		//UNDIRECTED GRAPH
		adjlist[u].push_back(make_pair(v,w));
        adjlist[v].push_back(make_pair(u,w));
	}
    dist.clear();
    dist.resize(n,INF);
	printf("enter source vertex\n");
	scanf("%d",&s);
	dijkstra(s);
	for(int i=0;i<n;i++)
	printf("%d->%d=%d\n",s,i,dist[i]);

	return 0;
}
